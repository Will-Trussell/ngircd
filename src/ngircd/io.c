/*
 * ngIRCd -- The Next Generation IRC Daemon
 * Copyright (c)2005-2006 Florian Westphal (westphal@foo.fh-furtwangen.de)
 * Copyright (c)2006-2014 Alexander Barton (alex@barton.de) and Contributors.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * Please read the file COPYING, README and AUTHORS for more information.
 */

#include "portab.h"

/**
 * @file
 * I/O abstraction interface.
 */

/* Extra debug messages in event add/delete/callback code: 0=off / 1=on */
#define DEBUG_IO 0

#include <assert.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "array.h"
#include "io.h"
#include "log.h"

typedef struct {
#ifdef PROTOTYPES
 void (*callback)(int, short);
#else
 void (*callback)();
#endif
 short what;
} io_event;

#define INIT_IOEVENT		{ NULL, -1, 0, NULL }
#define IO_ERROR		4
#define MAX_EVENTS		100

#ifdef HAVE_EPOLL_CREATE
#  define IO_USE_EPOLL		1
#  ifdef HAVE_SELECT
#    define IO_USE_SELECT	1
#  endif
#else
#  ifdef HAVE_KQUEUE
#    define IO_USE_KQUEUE	1
#  else
#    ifdef HAVE_SYS_DEVPOLL_H
#      define IO_USE_DEVPOLL	1
#    else
#      if defined(HAVE_POLL) && defined(HAVE_POLL_H)
#        define IO_USE_POLL	1
#      else
#        ifdef HAVE_SELECT
#          define IO_USE_SELECT	1
#        else
#          error "no IO API available!?"
#        endif /* HAVE_SELECT */
#      endif /* HAVE_POLL */
#    endif /* HAVE_SYS_DEVPOLL_H */
#  endif /* HAVE_KQUEUE */
#endif /* HAVE_EPOLL_CREATE */

static bool library_initialized = false;

#ifdef IO_USE_EPOLL
#include <sys/epoll.h>

static int io_masterfd = -1;
static bool io_event_change_epoll(int fd, short what, const int action);
static int io_dispatch_epoll(struct timeval *tv);
#endif

#ifdef IO_USE_KQUEUE
#include <sys/types.h>
#include <sys/event.h>
static array io_evcache;
static int io_masterfd;

static int io_dispatch_kqueue(struct timeval *tv);
static bool io_event_change_kqueue(int, short, const int action);

#ifndef EV_SET
/* Taken from /usr/include/sys/event.h of FreeBSD 8.1 and required by all
 * platforms that have kqueue but lack EV_SET() -- for example FreeBSD 4. */
#define EV_SET(kevp, a, b, c, d, e, f) do {	\
	struct kevent *__kevp__ = (kevp);	\
	__kevp__->ident = (a);			\
	__kevp__->filter = (b);			\
	__kevp__->flags = (c);			\
	__kevp__->fflags = (d);			\
	__kevp__->data = (e);			\
	__kevp__->udata = (f);			\
} while(0)
#endif
#endif

#ifdef IO_USE_POLL
#include <poll.h>

static array pollfds;
static int poll_maxfd;

static bool io_event_change_poll PARAMS((int fd, short what));
#endif

#ifdef IO_USE_DEVPOLL
#include <sys/devpoll.h>
static int io_masterfd;

static bool io_event_change_devpoll(int fd, short what);
#endif

#ifdef IO_USE_SELECT
#include <sys/time.h>
#include "defines.h"	/* for conn.h */
#include "proc.h"	/* for PROC_STAT (needed by conf.h) */
#include "conn.h"	/* for CONN_ID (needed by conf.h) */
#include "conf.h"	/* for Conf_MaxConnections */

static fd_set readers;
static fd_set writers;
/*
 * this is the first argument for select(), i.e.
 * the largest fd registered, plus one.
 */
static int select_maxfd;
static int io_dispatch_select PARAMS((struct timeval *tv));

#ifndef IO_USE_EPOLL
#define io_masterfd -1
#endif
#endif /* IO_USE_SELECT */

static array io_events;

static void io_docallback PARAMS((int fd, short what));

#if DEBUG_IO
static void
io_debug(const char *s, int fd, int what)
{
	Log(LOG_DEBUG, "%s: %d, %d\n", s, fd, what);
}
#else
static inline void
io_debug(const char UNUSED *s,int UNUSED a, int UNUSED b)
{ /* NOTHING */ }
#endif

static io_event *
io_event_get(int fd)
{
	io_event *i;

	assert(fd >= 0);

	i = (io_event *) array_get(&io_events, sizeof(io_event), (size_t) fd);

	assert(i != NULL);

	return i;
}

#ifdef IO_USE_EPOLL
static bool
io_event_change_epoll(int fd, short what, const int action)
{
	struct epoll_event ev = { 0, {0} };
	ev.data.fd = fd;

	if (what & IO_WANTREAD)
		ev.events = EPOLLIN | EPOLLPRI;
	if (what & IO_WANTWRITE)
		ev.events |= EPOLLOUT;

	return epoll_ctl(io_masterfd, action, fd, &ev) == 0;
}

static int
io_dispatch_epoll(struct timeval *tv)
{
	time_t sec = tv->tv_sec * 1000;
	int i, ret, timeout = tv->tv_usec + sec;
	struct epoll_event epoll_ev[MAX_EVENTS];
	short type;

	if (timeout < 0)
		timeout = 1000;

	ret = epoll_wait(io_masterfd, epoll_ev, MAX_EVENTS, timeout);

	for (i = 0; i < ret; i++) {
		type = 0;
		if (epoll_ev[i].events & (EPOLLERR | EPOLLHUP))
			type = IO_ERROR;

		if (epoll_ev[i].events & (EPOLLIN | EPOLLPRI))
			type |= IO_WANTREAD;

		if (epoll_ev[i].events & EPOLLOUT)
			type |= IO_WANTWRITE;

		io_docallback(epoll_ev[i].data.fd, type);
	}

	return ret;
}

static void
io_library_init_epoll(unsigned int eventsize)
{
	int ecreate_hint = (int)eventsize;
	if (ecreate_hint <= 0)
		ecreate_hint = 128;
	io_masterfd = epoll_create(ecreate_hint);
	if (io_masterfd >= 0) {
		library_initialized = true;
		Log(LOG_INFO,
		    "IO subsystem: epoll (hint size %d, initial maxfd %u, masterfd %d).",
		    ecreate_hint, eventsize, io_masterfd);
		return;
	}
#ifdef IO_USE_SELECT
	Log(LOG_INFO, "Can't initialize epoll() IO interface, falling back to select() ...");
#endif
}
#else
static inline void
io_library_init_epoll(unsigned int UNUSED ev)
{ /* NOTHING */ }
#endif /* IO_USE_EPOLL */

bool
io_library_init(unsigned int eventsize)
{
	if (library_initialized)
		return true;

	if ((eventsize > 0) && !array_alloc(&io_events, sizeof(io_event), (size_t)eventsize))
		eventsize = 0;

	io_library_init_epoll(eventsize);

	return library_initialized;
}

void
io_library_shutdown(void)
{
#ifdef IO_USE_SELECT
	FD_ZERO(&readers);
	FD_ZERO(&writers);
#endif
#if defined(IO_USE_EPOLL) || defined(IO_USE_KQUEUE) || defined(IO_USE_DEVPOLL)
	if (io_masterfd >= 0)
		close(io_masterfd);
	io_masterfd = -1;
#endif
#ifdef IO_USE_KQUEUE
	array_free(&io_evcache);
#endif
	library_initialized = false;
}


bool
io_event_setcb(int fd, void (*cbfunc) (int, short))
{
	io_event *i = io_event_get(fd);
	if (!i)
		return false;

	i->callback = cbfunc;
	return true;
}


static bool
backend_create_ev(int fd, short what)
{
	bool ret;
#ifdef IO_USE_DEVPOLL
	ret = io_event_change_devpoll(fd, what);
#endif
#ifdef IO_USE_POLL
	ret = io_event_change_poll(fd, what);
#endif
#ifdef IO_USE_EPOLL
	ret = io_event_change_epoll(fd, what, EPOLL_CTL_ADD);
#endif
#ifdef IO_USE_KQUEUE
	ret = io_event_change_kqueue(fd, what, EV_ADD|EV_ENABLE);
#endif
#ifdef IO_USE_SELECT
	if (io_masterfd < 0)
		ret = io_event_add(fd, what);
#endif
	return ret;
}


bool
io_event_create(int fd, short what, void (*cbfunc) (int, short))
{
	bool ret;
	io_event *i;

	assert(fd >= 0);
#if defined(IO_USE_SELECT) && defined(FD_SETSIZE)
	if (io_masterfd < 0 && fd >= FD_SETSIZE) {
		Log(LOG_ERR,
		    "fd %d exceeds FD_SETSIZE (%u) (select can't handle more file descriptors)",
		    fd, FD_SETSIZE);
		return false;
	}
#endif
	i = (io_event *) array_alloc(&io_events, sizeof(io_event), (size_t) fd);
	if (!i) {
		Log(LOG_WARNING,
		    "array_alloc failed: could not allocate space for %d io_event structures",
		    fd);
		return false;
	}

	i->callback = cbfunc;
	i->what = 0;
	ret = backend_create_ev(fd, what);
	if (ret)
		i->what = what;
	return ret;
}


bool
io_event_add(int fd, short what)
{
	io_event *i = io_event_get(fd);

	if (!i) return false;

	if ((i->what & what) == what) /* event type is already registered */
		return true;

	io_debug("io_event_add: fd, what", fd, what);

	i->what |= what;
#ifdef IO_USE_EPOLL
	if (io_masterfd >= 0)
		return io_event_change_epoll(fd, i->what, EPOLL_CTL_MOD);
#endif
#ifdef IO_USE_KQUEUE
	return io_event_change_kqueue(fd, what, EV_ADD | EV_ENABLE);
#endif
#ifdef IO_USE_DEVPOLL
	return io_event_change_devpoll(fd, i->what);
#endif
#ifdef IO_USE_POLL
	return io_event_change_poll(fd, i->what);
#endif
#ifdef IO_USE_SELECT
	if (fd > select_maxfd)
		select_maxfd = fd;

	if (what & IO_WANTREAD)
		FD_SET(fd, &readers);
	if (what & IO_WANTWRITE)
		FD_SET(fd, &writers);

	return true;
#endif
	return false;
}


bool
io_setnonblock(int fd)
{
	int flags = fcntl(fd, F_GETFL);
	if (flags == -1)
		return false;
#ifndef O_NONBLOCK
#define O_NONBLOCK O_NDELAY
#endif
	flags |= O_NONBLOCK;

	return fcntl(fd, F_SETFL, flags) == 0;
}

bool
io_setcloexec(int fd)
{
	int flags = fcntl(fd, F_GETFD);
	if (flags == -1)
		return false;
#ifdef FD_CLOEXEC
	flags |= FD_CLOEXEC;
#endif

	return fcntl(fd, F_SETFD, flags) == 0;
}

bool
io_close(int fd)
{
	io_event *i;

	i = io_event_get(fd);
#ifdef IO_USE_KQUEUE
	if (array_length(&io_evcache, sizeof (struct kevent)))	/* pending data in cache? */
		io_event_kqueue_commit_cache();

	/* both kqueue and epoll remove fd from all sets automatically on the last close
	 * of the descriptor. since we don't know if this is the last close we'll have
	 * to remove the set explicitly. */
	if (i) {
		io_event_change_kqueue(fd, i->what, EV_DELETE);
		io_event_kqueue_commit_cache();
	}
#endif
#ifdef IO_USE_EPOLL
	io_event_change_epoll(fd, 0, EPOLL_CTL_DEL);
#endif
	if (i) {
		i->callback = NULL;
		i->what = 0;
	}
	return close(fd) == 0;
}


bool
io_event_del(int fd, short what)
{
	io_event *i = io_event_get(fd);

	io_debug("io_event_del: trying to delete eventtype; fd, what", fd, what);
	if (!i) return false;

	if (!(i->what & what)) /* event is already disabled */
		return true;

	i->what &= ~what;
#ifdef IO_USE_EPOLL
	if (io_masterfd >= 0)
		return io_event_change_epoll(fd, i->what, EPOLL_CTL_MOD);
#endif
#ifdef IO_USE_SELECT
	if (what & IO_WANTWRITE)
		FD_CLR(fd, &writers);

	if (what & IO_WANTREAD)
		FD_CLR(fd, &readers);
	return true;
#endif
	return false;
}


int
io_dispatch(struct timeval *tv)
{
#ifdef IO_USE_EPOLL
	if (io_masterfd >= 0)
		return io_dispatch_epoll(tv);
#endif
	return -1;
}


/* call the callback function inside the struct matching fd */
static void
io_docallback(int fd, short what)
{
	io_event *i = io_event_get(fd);

	io_debug("io_docallback; fd, what", fd, what);

	if (i->callback) {	/* callback might be NULL if a previous callback function
				   called io_close on this fd */
		i->callback(fd, (what & IO_ERROR) ? i->what : what);
	}
	/* if error indicator is set, we return the event(s) that were registered */
}

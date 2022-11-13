// compile as e.g.    gcc example.c -o example -D_GNU_SOURCE -DUSE_VALGRIND -O3

#include <assert.h>
#include <errno.h>
#include <fcntl.h>
#include <stdalign.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdnoreturn.h>
#include <sys/epoll.h>
#include <sys/timerfd.h>
#include <threads.h>
#include <ucontext.h>
#include <unistd.h>

#ifdef USE_VALGRIND
#include <valgrind/valgrind.h>
#endif // USE_VALGRIND

/**
 * The data structure used to keep track of concurrently executing tasks.
 */
struct executor {
  /**
   * An epoll instance, which will ready with a pointer to the task which should
   * be woken up.
   */
  int epoll_fd;

  /**
   * A singly-linked list of stacks that should be freed. Tasks can't clean up
   * their own stacks, since they're still using them!
   */
  void **stacks_to_free;

  /**
   * A doubly-linked list of runnable tasks.
   */
  struct task *ready;

  /**
   * A doubly-linked list of tasks that are blocked on IO.
   */
  struct task *waiting;
};

/**
 * The data used by the scheduler to manage a single task.
 */
struct task {
  /**
   * Next and previous pointers for a doubly-linked list.
   */
  struct task *prev, *next;

  /**
   * The *numerically* lowest address of the task's stack.
   */
  void *stack_base;

  /**
   * The number of bytes in the task's stack.
   */
  size_t stack_size;

  /**
   * The continuation of the task.
   */
  ucontext_t ctx;

  /**
   * A flag for whether the task expects itself to be scheduled.
   */
  bool scheduled;

  /**
   * The file descriptor the task is waiting on, if any.
   */
  int waiting_on_fd;
};

/**
 * The default stack size for new tasks.
 */
static const size_t STACK_SIZE = 4096 * 16;

/**
 * The currently-used executor.
 */
static thread_local struct executor *current_executor;

/**
 * The currently-running task.
 */
static thread_local struct task *current_task;

/**
 * Runs the next task, without implicitly returning to the currently running
 * one, and assuming that the ready queue pointer has already been advanced.
 */
noreturn void task_run_next(void) {
  current_task = current_executor->ready;
  current_task->scheduled = true;
  setcontext(&current_task->ctx);
  perror("setcontext");
  abort();
}

/**
 * The helper function that wraps the task function. Only used by task_new.
 */
static void task_helper(int func_hi, int func_lo, int cloptr_hi,
                        int cloptr_lo) {
  // Reconstruct the pointers.
  static_assert(sizeof(int) == 4, "int had the wrong size; port this code");
  static_assert(sizeof(uintptr_t) == 8,
                "uintptr_t had the wrong size; port this code");
  uintptr_t func_addr = (((uintptr_t)func_hi) << 32) | (uintptr_t)func_lo;
  uintptr_t cloptr_addr = (((uintptr_t)cloptr_hi) << 32) | (uintptr_t)cloptr_lo;
  void (*func)(void *) = (void (*)(void *))func_addr;
  void *cloptr = (void *)cloptr_addr;

  // Run the task.
  func(cloptr);

  // Unlink the task from the queue, and advance to the next task.
  current_task->prev->next = current_task->next;
  current_task->next->prev = current_task->prev;
  current_executor->ready = current_task->next;

  // Push the stack to the stacks_to_free list.
  *(void **)current_task->stack_base = current_executor->stacks_to_free;
  current_executor->stacks_to_free = current_task->stack_base;

  // Free the task.
  free(current_task);
  current_task = NULL;

  // Run a next task.
  task_run_next();
}

/**
 * Creates a new task that will invoke the given function pointer, passing it
 * cloptr.
 */
struct task *task_new(void (*func)(void *cloptr), void *cloptr) {
  // Allocate the task and stack.
  struct task *task = malloc(sizeof(struct task));
  if (!task)
    return NULL;
  void *stack = malloc(STACK_SIZE);
  if (!stack) {
    int err = errno;
    free(task);
    errno = err;
    return NULL;
  }

  // Slice and dice func and cloptr so they can be passed to makecontext.
  //
  // This is... perhaps somewhat questionable in terms of pointer provenance.
  // Nonetheless, it ought to be defined under PNVI-ae-udi, since func and
  // cloptr explicitly become exposed.
  static_assert(sizeof(int) == 4, "int had the wrong size; port this code");
  static_assert(sizeof(uintptr_t) == 8,
                "uintptr_t had the wrong size; port this code");
  uintptr_t func_addr = (uintptr_t)func;
  uintptr_t cloptr_addr = (uintptr_t)cloptr;
  int func_hi = (unsigned)(func_addr >> 32);
  int func_lo = (unsigned)(func_addr);
  int cloptr_hi = (unsigned)(cloptr_addr >> 32);
  int cloptr_lo = (unsigned)(cloptr_addr);

  // Set up the task context.
  if (getcontext(&task->ctx)) {
    int err = errno;
    free(stack);
    free(task);
    errno = err;
    return NULL;
  }

  // Initialize the task.
  task->prev = task->next = task;
  task->stack_base = stack;
  task->stack_size = STACK_SIZE;
  task->ctx.uc_stack.ss_sp = stack + sizeof(void *);
  task->ctx.uc_stack.ss_size = STACK_SIZE - sizeof(void *);
  makecontext(&task->ctx, (void (*)())task_helper, 4, func_hi, func_lo,
              cloptr_hi, cloptr_lo);
  task->scheduled = false;

  // If compiling with Valgrind instrumentation, register the stack.
#ifdef USE_VALGRIND
  VALGRIND_STACK_REGISTER(stack, stack + STACK_SIZE);
#endif // USE_VALGRIND

  return task;
}

/**
 * Creates a new task that will invoke the given function pointer, passing it
 * cloptr, and schedules it in the executor, crashing on OOM.
 */
void task_spawn(void (*func)(void *cloptr), void *cloptr) {
  // Create the new task.
  struct task *task = task_new(func, cloptr);
  if (!task) {
    int err = errno;
    fprintf(stderr, "could not spawn function %p", (void *)func);
    errno = err;
    perror("");
    abort();
  }

  // Put the task into the ready queue.
  struct task *prev = current_executor->ready, *next = prev->next;
  prev->next = task;
  next->prev = task;
  task->prev = prev;
  task->next = next;
}

/**
 * Yields to the next ready task, without moving the current task to the waiting
 * queue.
 */
void task_yield_to(struct task *next) {
  // Store the old context.
  current_task->scheduled = false;
  if (getcontext(&current_task->ctx)) {
    perror("getcontext");
    abort();
  }

  // getcontext() will return twice, once when the call initially completes and
  // once when the task is re-scheduled. When the task gets re-scheduled, its
  // scheduled flag will be set; otherwise, we should go to the next task.
  if (!current_task->scheduled) {
    current_executor->ready = next;
    task_run_next();
  }
}

/**
 * Yields to the next ready task, without moving the current task to the waiting
 * queue.
 */
void task_yield(void) { task_yield_to(current_task->next); }

/**
 * Yields to the next ready task, moving the current task to the waiting queue
 * and registering it to be woken up when the given epoll event occurs.
 */
void task_yield_for_io(int fd, int events) {
  // Register to be woken up.
  struct epoll_event event = {
      .events = events,
      .data = {.ptr = current_task},
  };
  current_task->waiting_on_fd = fd;
  if (epoll_ctl(current_executor->epoll_fd, EPOLL_CTL_ADD, fd, &event) == -1) {
    perror("epoll_ctl");
    abort();
  }

  // Get the task to continue to.
  struct task *next_ready = current_task->next;

  // Unlink the task from the ready queue.
  current_task->prev->next = current_task->next;
  current_task->next->prev = current_task->prev;

  // Add the task to the waiting queue.
  struct task *prev = current_executor->waiting, *next = prev->next;
  prev->next = current_task;
  next->prev = current_task;
  current_task->prev = prev;
  current_task->next = next;

  // Yield to the next task in the ready queue.
  task_yield_to(next_ready);
}

/**
 * The size of the stack the idle task gets. This can be much smaller than the
 * stack size for user code, since the idle task is so minimal.
 */
#define IDLE_TASK_STACK_SIZE 4096 * 16

/**
 * The idle task. This task:
 *
 * - Checks if any waiting tasks are now schedulable.
 * - If none are, waits until an IO operation is done.
 * - If there are no waiting tasks and no ready tasks, cleans up the executor
 *   and exits.
 */
static void idle_task(void) {
  // The idle task runs until it's the only runnable task, and only the dummy
  // task is waiting. (In that case, there will never be an IO ready if we wait,
  // and there's no other work to do.)
  while (current_executor->ready != current_executor->ready->next ||
         current_executor->waiting != current_executor->waiting->next) {
    // Initially, the timeout is zero, because we don't want to wait for IOs
    // before we yield (there might be other ready tasks in the queue); on
    // subsequent iterations, it's -1, so that we wait forever.
    int timeout = 0;
    do {
      // Check for finished IOs.
      struct epoll_event events[8];
      int num_ready =
          epoll_wait(current_executor->epoll_fd, &events[0], 8, timeout);
      if (num_ready == -1) {
        perror("epoll_wait");
        abort();
      }

      // Schedule each newly ready task.
      for (size_t i = 0; i < (size_t)num_ready; i++) {
        struct task *task = events[i].data.ptr;

        // Unregister interest in the fd.
        if (epoll_ctl(current_executor->epoll_fd, EPOLL_CTL_DEL,
                      task->waiting_on_fd, NULL) == -1) {
          perror("epoll_ctl");
          abort();
        }
        task->waiting_on_fd = -1;

        // Unlink the task from the waiting queue.
        task->prev->next = task->next;
        task->next->prev = task->prev;

        // Link the task into the ready queue, behind the current task.
        struct task *prev = current_task->prev, *next = current_task;
        prev->next = task;
        next->prev = task;
        task->prev = prev;
        task->next = next;
      }

      // If we're going to loop again, we'll be waiting indefinitely.
      timeout = -1;

      // Loop again if there's no ready task.
    } while (current_task == current_task->next);

    // There's another ready task now, so we yield to it.
    task_yield();

    // Check if we have any stacks to clean up.
    while (current_executor->stacks_to_free) {
      void **stack = current_executor->stacks_to_free;
      current_executor->stacks_to_free = *stack;
      free(stack);
    }
  }

  // TODO: Clean up the executor and exit.
  fprintf(stderr, "TODO: all tasks done\n");
  abort();
}

/**
 * Creates a new executor.
 */
struct executor *executor_new(void) {
  // Create the epoll fd.
  int epoll_fd = epoll_create1(EPOLL_CLOEXEC);
  if (epoll_fd == -1) {
    int err = errno;
    perror("epoll_create1");
    errno = err;
    return NULL;
  }

  // Allocate the executor, plus space for two tasks and the idle task's stack.
  struct executor_block {
    struct executor executor;
    struct task idle_task;
    struct task dummy_task;
    // On aarch64 and amd64, the stack needs to be 16-byte aligned.
    alignas(16) char ready_task_stack[IDLE_TASK_STACK_SIZE];
  };
  struct executor_block *executor_block = malloc(sizeof(struct executor_block));
  if (!executor_block) {
    int err = errno;
    perror("malloc");
    close(epoll_fd);
    errno = err;
    return NULL;
  }

  // Initialize the waiting queue's dummy task. This will never need to be run,
  // so it's fine that we're going to call a null function with a null stack if
  // we try to.
  executor_block->dummy_task = (struct task){
      .prev = &executor_block->dummy_task,
      .next = &executor_block->dummy_task,
      .stack_base = 0,
      .stack_size = 0,
      .ctx = {0},
      .scheduled = false,
      .waiting_on_fd = -1,
  };

  // Initialize the ready queue's idle task. This is what actually waits on the
  // epoll fd, so it _does_ need to be runnable. It doesn't need much stack,
  // though.
  executor_block->idle_task = (struct task){
      .prev = &executor_block->idle_task,
      .next = &executor_block->idle_task,
      .stack_base = executor_block->ready_task_stack,
      .stack_size = IDLE_TASK_STACK_SIZE,
      .ctx = {0},
      .scheduled = false,
      .waiting_on_fd = -1,
  };

  // Set up the task context for the idle task.
  if (getcontext(&executor_block->idle_task.ctx)) {
    int err = errno;
    perror("getcontext");
    close(epoll_fd);
    errno = err;
    return NULL;
  }
  executor_block->idle_task.ctx.uc_stack.ss_sp =
      &executor_block->ready_task_stack[0];
  executor_block->idle_task.ctx.uc_stack.ss_size = IDLE_TASK_STACK_SIZE;
  makecontext(&executor_block->idle_task.ctx, idle_task, 0);

  // If compiling with Valgrind instrumentation, register the stack.
#ifdef USE_VALGRIND
  VALGRIND_STACK_REGISTER(
      &executor_block->ready_task_stack[0],
      &executor_block->ready_task_stack[IDLE_TASK_STACK_SIZE]);
#endif // USE_VALGRIND

  // Initialize the executor.
  executor_block->executor = (struct executor){
      .epoll_fd = epoll_fd,
      .stacks_to_free = NULL,
      .ready = &executor_block->idle_task,
      .waiting = &executor_block->dummy_task,
  };

  // Return the executor.
  return &executor_block->executor;
}

/**
 * Creates a new executor, spawns a task on it, and runs until all tasks
 * complete (the given one and any it spawns), exiting afterwards.
 *
 * Crashes on OOM, fd exhaustion, etc.
 */
noreturn void run_with_executor(void (*func)(void *cloptr), void *cloptr) {
  struct executor *executor = executor_new();
  if (!executor) {
    perror("executor_new");
    abort();
  }

  current_executor = executor;
  task_spawn(func, cloptr);
  task_run_next();
}

/**
 * Attempts to read count bytes from fd into buf. Returns the number of bytes
 * actually read. If an error or EOF is encountered, this will be less than
 * count.
 *
 * Error and EOF may be distinguished by the value of errno; if errno is zero,
 * EOF was reached.
 */
size_t read_to_end(int fd, void *buf, size_t count) {
  // Check that the file is configured for non-blocking IO.
#ifndef NDEBUG
  int fd_flags = fcntl(fd, F_GETFL);
  if (fd_flags == -1)
    return 0;
  assert(fd_flags & O_NONBLOCK);
#endif // NDEBUG

  size_t bytes_read = 0;
  while (bytes_read < count) {
    ssize_t len = read(fd, buf + bytes_read, count - bytes_read);
    if (len == -1) {
      if (errno == EAGAIN || errno == EWOULDBLOCK) {
        // This would block, so yield and continue reading.
        task_yield_for_io(fd, EPOLLIN);
      } else if (errno == EINTR) {
        // We were interrupted by a signal, continue reading.
      } else {
        // We got a real error! Exit with a short count.
        return bytes_read;
      }
    } else if (len == 0) {
      // We're at EOF. Exit with a short count.
      break;
    } else {
      // We got some bytes, advance bytes_read.
      bytes_read += len;
    }
  }

  errno = 0;
  return bytes_read;
}

/**
 * Attempts to write count bytes from buf into fd. Returns the number of bytes
 * actually written. If an error is encountered, returns -1; otherwise, 0.
 */
int write_to_end(int fd, const void *buf, size_t count) {
  // Check that the file is configured for non-blocking IO.
#ifndef NDEBUG
  int fd_flags = fcntl(fd, F_GETFL);
  if (fd_flags == -1)
    return -1;
  assert(fd_flags & O_NONBLOCK);
#endif // NDEBUG

  while (count) {
    ssize_t len = write(fd, buf, count);
    if (len == -1) {
      if (errno == EAGAIN || errno == EWOULDBLOCK) {
        // This would block, so yield and continue writing.
        task_yield_for_io(fd, EPOLLOUT);
      } else if (errno == EINTR) {
        // We were interrupted by a signal, continue writing.
      } else {
        // We got a real error! Exit with a short count.
        return -1;
      }
    } else {
      // We got some bytes, advance buf and count.
      buf += len;
      count -= len;
    }
  }

  errno = 0;
  return 0;
}

/**
 * Puts the task to sleep for the given amount of time. If an error is
 * encountered, returns -1; otherwise, 0.
 */
int task_sleep_nanos(time_t seconds, long nanoseconds) {
  // Allocate a timerfd.
  int fd = timerfd_create(CLOCK_REALTIME, TFD_CLOEXEC | TFD_NONBLOCK);
  if (fd == -1)
    return -1;

  // Set the timer.
  struct itimerspec timerspec = {
      .it_interval = {0},
      .it_value = {.tv_sec = seconds, .tv_nsec = nanoseconds},
  };
  if (timerfd_settime(fd, 0, &timerspec, NULL) == -1) {
    int err = errno;
    close(fd);
    errno = err;
    return -1;
  }

  // Wait for the timer.
  task_yield_for_io(fd, EPOLLIN);

  // Free the timerfd.
  return close(fd);
}

/// TESTING CODE

struct task2_ctx {
  const char *name;
  int read_pipe;
  int write_pipe;
};

static void task2(struct task2_ctx *ctx) {
  const char *name = ctx->name;
  int read_pipe = ctx->read_pipe;
  int write_pipe = ctx->write_pipe;
  free(ctx);

  char buf[4];
  while (1) {
    if (read_to_end(read_pipe, buf, 4) != 4) {
      int err = errno;
      fprintf(stderr, "[%s] ", name);
      errno = err;
      perror("read_to_end");
      goto end;
    }

    for (int i = 0; i < 4; i++) {
      fprintf(stderr, "[%s] %c\n", name, buf[i]);
      if (write_to_end(write_pipe, &buf[i], 1)) {
        int err = errno;
        fprintf(stderr, "[%s] ", name);
        errno = err;
        perror("write_to_end");
        abort();
      }
      task_yield();
    }
  }

end:
  close(read_pipe);
  close(write_pipe);
}

static void task1(void *ignored) {
  (void)ignored;

  int pipefds[4];
  if (pipe2(&pipefds[0], O_CLOEXEC | O_NONBLOCK)) {
    perror("pipe");
    abort();
  }
  if (pipe2(&pipefds[2], O_CLOEXEC | O_NONBLOCK)) {
    perror("pipe");
    abort();
  }

  struct task2_ctx *ctx1 = malloc(sizeof(struct task2_ctx));
  if (!ctx1) {
    perror("malloc");
    abort();
  }

  struct task2_ctx *ctx2 = malloc(sizeof(struct task2_ctx));
  if (!ctx2) {
    perror("malloc");
    abort();
  }

  *ctx1 = (struct task2_ctx){
      .name = "0->3",
      .read_pipe = pipefds[0],
      .write_pipe = pipefds[3],
  };
  *ctx2 = (struct task2_ctx){
      .name = "2->1",
      .read_pipe = pipefds[2],
      .write_pipe = pipefds[1],
  };

  task_spawn((void (*)(void *))task2, ctx1);
  task_spawn((void (*)(void *))task2, ctx2);
  task_yield();

  task_sleep_nanos(1, 0);

  if (write_to_end(pipefds[1], "/-\\|", 4)) {
    perror("write_to_end");
    abort();
  }
}

int main(void) { run_with_executor(task1, NULL); }

typedef unsigned char __u_char;
typedef unsigned short __u_short;
typedef unsigned int __u_int;
typedef unsigned long __u_long;
typedef char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short __int16_t;
typedef unsigned short __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;
typedef signed long __int64_t;
typedef unsigned long __uint64_t;
typedef __int8_t __int_least8_t;
typedef __uint8_t __uint_least8_t;
typedef __int16_t __int_least16_t;
typedef __uint16_t __uint_least16_t;
typedef __int32_t __int_least32_t;
typedef __uint32_t __uint_least32_t;
typedef __int64_t __int_least64_t;
typedef __uint64_t __uint_least64_t;
typedef signed long __quad_t;
typedef unsigned long __u_quad_t;
typedef signed long __intmax_t;
typedef unsigned long __uintmax_t;
typedef unsigned long __dev_t;
typedef unsigned int __uid_t;
typedef unsigned int __gid_t;
typedef unsigned long __ino_t;
typedef unsigned long __ino64_t;
typedef unsigned int __mode_t;
typedef unsigned long __nlink_t;
typedef signed long __off_t;
typedef signed long __off64_t;
typedef signed int __pid_t;
typedef struct anon__usr_include_bits_types_h_155_8 {
  signed int __val[2];
  
} __fsid_t;
typedef signed long __clock_t;
typedef unsigned long __rlim_t;
typedef unsigned long __rlim64_t;
typedef unsigned int __id_t;
typedef signed long __time_t;
typedef unsigned int __useconds_t;
typedef signed long __suseconds_t;
typedef signed long __suseconds64_t;
typedef signed int __daddr_t;
typedef signed int __key_t;
typedef signed int __clockid_t;
typedef void  *__timer_t;
typedef signed long __blksize_t;
typedef signed long __blkcnt_t;
typedef signed long __blkcnt64_t;
typedef unsigned long __fsblkcnt_t;
typedef unsigned long __fsblkcnt64_t;
typedef unsigned long __fsfilcnt_t;
typedef unsigned long __fsfilcnt64_t;
typedef signed long __fsword_t;
typedef signed long __ssize_t;
typedef signed long __syscall_slong_t;
typedef unsigned long __syscall_ulong_t;
typedef __off64_t __loff_t;
typedef char  *__caddr_t;
typedef signed long __intptr_t;
typedef unsigned int __socklen_t;
typedef signed int __sig_atomic_t;
typedef __ino_t ino_t;
typedef __dev_t dev_t;
typedef __gid_t gid_t;
typedef __mode_t mode_t;
typedef __nlink_t nlink_t;
typedef __uid_t uid_t;
typedef __off_t off_t;
typedef __pid_t pid_t;
typedef __id_t id_t;
typedef __ssize_t ssize_t;
typedef __clock_t clock_t;
typedef __clockid_t clockid_t;
typedef __time_t time_t;
typedef __timer_t timer_t;
typedef unsigned long size_t;
typedef __int8_t int8_t;
typedef __int16_t int16_t;
typedef __int32_t int32_t;
typedef __int64_t int64_t;
typedef __uint8_t u_int8_t;
typedef __uint16_t u_int16_t;
typedef __uint32_t u_int32_t;
typedef __uint64_t u_int64_t;
typedef signed int register_t __attribute__((__mode__(__word__)));
typedef __blksize_t blksize_t;
typedef __blkcnt_t blkcnt_t;
typedef __fsblkcnt_t fsblkcnt_t;
typedef __fsfilcnt_t fsfilcnt_t;
typedef union anon__usr_include_bits_atomic_wide_counter_h_25_8 {
  unsigned long long __value64;
  struct anon__usr_include_bits_atomic_wide_counter_h_28_2 {
    unsigned int __low;
    unsigned int __high;
    
  } __value32;
  
} __atomic_wide_counter;
typedef struct __pthread_internal_list {
  struct __pthread_internal_list  *__prev;
  struct __pthread_internal_list  *__next;
  
} __pthread_list_t;
typedef struct __pthread_internal_slist {
  struct __pthread_internal_slist  *__next;
  
} __pthread_slist_t;
struct __pthread_mutex_s {
  signed int __lock;
  unsigned int __count;
  signed int __owner;
  unsigned int __nusers;
  signed int __kind;
  signed short __spins;
  signed short __elision;
  __pthread_list_t __list;
  
};
struct __pthread_rwlock_arch_t {
  unsigned int __readers;
  unsigned int __writers;
  unsigned int __wrphase_futex;
  unsigned int __writers_futex;
  unsigned int __pad3;
  unsigned int __pad4;
  signed int __cur_writer;
  signed int __shared;
  char __rwelision;
  unsigned char __pad1[7];
  unsigned long __pad2;
  unsigned int __flags;
  
};
struct __pthread_cond_s {
  __atomic_wide_counter __wseq;
  __atomic_wide_counter __g1_start;
  unsigned int __g_refs[2];
  unsigned int __g_size[2];
  unsigned int __g1_orig_size;
  unsigned int __wrefs;
  unsigned int __g_signals[2];
  
};
typedef unsigned int __tss_t;
typedef unsigned long __thrd_t;
typedef struct anon__usr_include_bits_thread_shared_types_h_108_8 {
  signed int __data;
  
} __once_flag;
typedef unsigned long pthread_t;
typedef union anon__usr_include_bits_pthreadtypes_h_32_8 {
  char __size[4];
  signed int __align;
  
} pthread_mutexattr_t;
typedef union anon__usr_include_bits_pthreadtypes_h_41_8 {
  char __size[4];
  signed int __align;
  
} pthread_condattr_t;
typedef unsigned int pthread_key_t;
typedef signed int pthread_once_t;
union pthread_attr_t {
  char __size[56];
  signed long __align;
  
};
typedef union pthread_attr_t pthread_attr_t;
typedef union anon__usr_include_bits_pthreadtypes_h_67_8 {
  struct __pthread_mutex_s __data;
  char __size[40];
  signed long __align;
  
} pthread_mutex_t;
typedef union anon__usr_include_bits_pthreadtypes_h_75_8 {
  struct __pthread_cond_s __data;
  char __size[48];
  signed long long __align;
  
} pthread_cond_t;
typedef union anon__usr_include_bits_pthreadtypes_h_86_8 {
  struct __pthread_rwlock_arch_t __data;
  char __size[56];
  signed long __align;
  
} pthread_rwlock_t;
typedef union anon__usr_include_bits_pthreadtypes_h_93_8 {
  char __size[8];
  signed long __align;
  
} pthread_rwlockattr_t;
typedef volatile signed int pthread_spinlock_t;
typedef union anon__usr_include_bits_pthreadtypes_h_108_8 {
  char __size[32];
  signed long __align;
  
} pthread_barrier_t;
typedef union anon__usr_include_bits_pthreadtypes_h_114_8 {
  char __size[4];
  signed int __align;
  
} pthread_barrierattr_t;
typedef signed long ptrdiff_t;
typedef signed int wchar_t;
typedef struct anon__usr_lib_gcc_x86_64_pc_linux_gnu_11_3_0_include_stddef_h_415_8 {
  signed long long __max_align_ll __attribute__((__aligned__((_Alignof(signed long long)))));
  long double __max_align_ld __attribute__((__aligned__((_Alignof(long double)))));
  
} max_align_t;
typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;
typedef __uint32_t uint32_t;
typedef __uint64_t uint64_t;
typedef __int_least8_t int_least8_t;
typedef __int_least16_t int_least16_t;
typedef __int_least32_t int_least32_t;
typedef __int_least64_t int_least64_t;
typedef __uint_least8_t uint_least8_t;
typedef __uint_least16_t uint_least16_t;
typedef __uint_least32_t uint_least32_t;
typedef __uint_least64_t uint_least64_t;
typedef char int_fast8_t;
typedef signed long int_fast16_t;
typedef signed long int_fast32_t;
typedef signed long int_fast64_t;
typedef unsigned char uint_fast8_t;
typedef unsigned long uint_fast16_t;
typedef unsigned long uint_fast32_t;
typedef unsigned long uint_fast64_t;
typedef signed long intptr_t;
typedef unsigned long uintptr_t;
typedef __intmax_t intmax_t;
typedef __uintmax_t uintmax_t;
typedef signed int __gwchar_t;
typedef struct anon__usr_include_inttypes_h_271_8 {
  signed long quot;
  signed long rem;
  
} imaxdiv_t;
extern intmax_t imaxabs(intmax_t  __n);
extern imaxdiv_t imaxdiv(intmax_t  __numer, intmax_t  __denom);
extern intmax_t strtoimax(const char  *__restrict  __nptr, char  * *__restrict  __endptr, signed int  __base);
extern uintmax_t strtoumax(const char  *__restrict  __nptr, char  * *__restrict  __endptr, signed int  __base);
extern intmax_t wcstoimax(const __gwchar_t  *__restrict  __nptr, __gwchar_t  * *__restrict  __endptr, signed int  __base);
extern uintmax_t wcstoumax(const __gwchar_t  *__restrict  __nptr, __gwchar_t  * *__restrict  __endptr, signed int  __base);
typedef void POINTER;
typedef uint8_t UINT8;
typedef uint16_t UINT16;
typedef uint32_t UINT32;
extern size_t strlcat(char  * dst, const char  * src, size_t  size);
extern size_t strlcpy(char  * dst, const char  * src, size_t  size);
typedef struct anon_array_h_22_8 {
  char  *mem;
  size_t allocated;
  size_t used;
  
} array;
extern void array_init(array  * a);
extern void  *array_alloc(array  * a, size_t  size, size_t  pos);
extern size_t array_length(const array  *const  a, size_t  elemsize);
extern _Bool array_copy(array  * dest, const array  *const  src);
extern _Bool array_copyb(array  * dest, const char  * src, size_t  len);
extern _Bool array_copys(array  * dest, const char  * src);
extern _Bool array_catb(array  * dest, const char  * src, size_t  len);
extern _Bool array_cats(array  * dest, const char  * src);
extern _Bool array_cat0(array  * dest);
extern _Bool array_cat0_temporary(array  * dest);
extern _Bool array_cat(array  * dest, const array  *const  src);
extern void  *array_get(array  * a, size_t  membersize, size_t  pos);
extern void array_free(array  * a);
extern void array_free_wipe(array  * a);
extern void  *array_start(const array  *const  a);
extern void array_trunc(array  * a);
extern void array_truncate(array  * a, size_t  membersize, size_t  len);
extern void array_moveleft(array  * a, size_t  membersize, size_t  pos);
typedef struct anon__usr_include_stdlib_h_59_8 {
  signed int quot;
  signed int rem;
  
} div_t;
typedef struct anon__usr_include_stdlib_h_67_8 {
  signed long quot;
  signed long rem;
  
} ldiv_t;
typedef struct anon__usr_include_stdlib_h_77_22 {
  signed long long quot;
  signed long long rem;
  
} lldiv_t;
extern size_t __ctype_get_mb_cur_max(void);
extern double atof(const char  * __nptr);
extern signed int atoi(const char  * __nptr);
extern signed long atol(const char  * __nptr);
extern signed long long atoll(const char  * __nptr);
extern double strtod(const char  *__restrict  __nptr, char  * *__restrict  __endptr);
extern float strtof(const char  *__restrict  __nptr, char  * *__restrict  __endptr);
extern long double strtold(const char  *__restrict  __nptr, char  * *__restrict  __endptr);
extern signed long strtol(const char  *__restrict  __nptr, char  * *__restrict  __endptr, signed int  __base);
extern unsigned long strtoul(const char  *__restrict  __nptr, char  * *__restrict  __endptr, signed int  __base);
extern signed long long strtoll(const char  *__restrict  __nptr, char  * *__restrict  __endptr, signed int  __base);
extern unsigned long long strtoull(const char  *__restrict  __nptr, char  * *__restrict  __endptr, signed int  __base);
extern signed int rand(void);
extern void srand(unsigned int  __seed);
extern signed int rand_r(unsigned int  * __seed);
extern void  *malloc(size_t  __size);
extern void  *calloc(size_t  __nmemb, size_t  __size);
extern void  *realloc(void  * __ptr, size_t  __size);
extern void free(void  * __ptr);
extern signed int posix_memalign(void  * * __memptr, size_t  __alignment, size_t  __size);
extern void  *aligned_alloc(size_t  __alignment, size_t  __size);
extern void abort(void);
extern signed int atexit(void ( * __func)(void));
extern signed int at_quick_exit(void ( * __func)(void));
extern void exit(signed int  __status);
extern void quick_exit(signed int  __status);
extern void _Exit(signed int  __status);
extern char  *getenv(const char  * __name);
extern signed int setenv(const char  * __name, const char  * __value, signed int  __replace);
extern signed int unsetenv(const char  * __name);
extern signed int mkstemp(char  * __template);
extern char  *mkdtemp(char  * __template);
extern signed int system(const char  * __command);
typedef signed int ( *__compar_fn_t)(const void  * , const void  * );
extern void  *bsearch(const void  * __key, const void  * __base, size_t  __nmemb, size_t  __size, __compar_fn_t  __compar);
extern void qsort(void  * __base, size_t  __nmemb, size_t  __size, __compar_fn_t  __compar);
extern signed int abs(signed int  __x);
extern signed long labs(signed long  __x);
extern signed long long llabs(signed long long  __x);
extern div_t div(signed int  __numer, signed int  __denom);
extern ldiv_t ldiv(signed long  __numer, signed long  __denom);
extern lldiv_t lldiv(signed long long  __numer, signed long long  __denom);
extern signed int mblen(const char  * __s, size_t  __n);
extern signed int mbtowc(wchar_t  *__restrict  __pwc, const char  *__restrict  __s, size_t  __n);
extern signed int wctomb(char  * __s, wchar_t  __wchar);
extern size_t mbstowcs(wchar_t  *__restrict  __pwcs, const char  *__restrict  __s, size_t  __n);
extern size_t wcstombs(char  *__restrict  __s, const wchar_t  *__restrict  __pwcs, size_t  __n);
extern signed int getsubopt(char  * *__restrict  __optionp, char  *const  *__restrict  __tokens, char  * *__restrict  __valuep);
typedef __builtin_va_list __gnuc_va_list;
typedef struct anon__usr_include_bits_types___mbstate_t_h_13_8 {
  signed int __count;
  union anon__usr_include_bits_types___mbstate_t_h_16_2 {
    unsigned int __wch;
    char __wchb[4];
    
  } __value;
  
} __mbstate_t;
typedef struct _G_fpos_t {
  __off_t __pos;
  __mbstate_t __state;
  
} __fpos_t;
typedef struct _G_fpos64_t {
  __off64_t __pos;
  __mbstate_t __state;
  
} __fpos64_t;
struct _IO_FILE;
typedef struct _IO_FILE __FILE;
struct _IO_FILE;
typedef struct _IO_FILE FILE;
struct _IO_FILE;
struct _IO_marker;
struct _IO_codecvt;
struct _IO_wide_data;
typedef void _IO_lock_t;
struct _IO_FILE {
  signed int _flags;
  char  *_IO_read_ptr;
  char  *_IO_read_end;
  char  *_IO_read_base;
  char  *_IO_write_base;
  char  *_IO_write_ptr;
  char  *_IO_write_end;
  char  *_IO_buf_base;
  char  *_IO_buf_end;
  char  *_IO_save_base;
  char  *_IO_backup_base;
  char  *_IO_save_end;
  struct _IO_marker  *_markers;
  struct _IO_FILE  *_chain;
  signed int _fileno;
  signed int _flags2;
  __off_t _old_offset;
  unsigned short _cur_column;
  char _vtable_offset;
  char _shortbuf[1];
  _IO_lock_t  *_lock;
  __off64_t _offset;
  struct _IO_codecvt  *_codecvt;
  struct _IO_wide_data  *_wide_data;
  struct _IO_FILE  *_freeres_list;
  void  *_freeres_buf;
  size_t __pad5;
  signed int _mode;
  char _unused2[(((15 * (sizeof(signed int))) - (4 * (sizeof(void *)))) - (sizeof(size_t)))];
  
};
typedef __gnuc_va_list va_list;
typedef __fpos_t fpos_t;
extern FILE  *stdin;
extern FILE  *stdout;
extern FILE  *stderr;
extern signed int remove(const char  * __filename);
extern signed int rename(const char  * __old, const char  * __new);
extern signed int renameat(signed int  __oldfd, const char  * __old, signed int  __newfd, const char  * __new);
extern signed int fclose(FILE  * __stream);
extern FILE  *tmpfile(void);
extern char  *tmpnam(char  [20]);
extern signed int fflush(FILE  * __stream);
extern FILE  *fopen(const char  *__restrict  __filename, const char  *__restrict  __modes);
extern FILE  *freopen(const char  *__restrict  __filename, const char  *__restrict  __modes, FILE  *__restrict  __stream);
extern FILE  *fdopen(signed int  __fd, const char  * __modes);
extern FILE  *fmemopen(void  * __s, size_t  __len, const char  * __modes);
extern FILE  *open_memstream(char  * * __bufloc, size_t  * __sizeloc);
extern void setbuf(FILE  *__restrict  __stream, char  *__restrict  __buf);
extern signed int setvbuf(FILE  *__restrict  __stream, char  *__restrict  __buf, signed int  __modes, size_t  __n);
extern signed int fprintf(FILE  *__restrict  __stream, const char  *__restrict  __format, ...);
extern signed int printf(const char  *__restrict  __format, ...);
extern signed int sprintf(char  *__restrict  __s, const char  *__restrict  __format, ...);
extern signed int vfprintf(FILE  *__restrict  __s, const char  *__restrict  __format, __gnuc_va_list  __arg);
extern signed int vprintf(const char  *__restrict  __format, __gnuc_va_list  __arg);
extern signed int vsprintf(char  *__restrict  __s, const char  *__restrict  __format, __gnuc_va_list  __arg);
extern signed int snprintf(char  *__restrict  __s, size_t  __maxlen, const char  *__restrict  __format, ...);
extern signed int vsnprintf(char  *__restrict  __s, size_t  __maxlen, const char  *__restrict  __format, __gnuc_va_list  __arg);
extern signed int vdprintf(signed int  __fd, const char  *__restrict  __fmt, __gnuc_va_list  __arg);
extern signed int dprintf(signed int  __fd, const char  *__restrict  __fmt, ...);
extern signed int fscanf(FILE  *__restrict  __stream, const char  *__restrict  __format, ...);
extern signed int scanf(const char  *__restrict  __format, ...);
extern signed int sscanf(const char  *__restrict  __s, const char  *__restrict  __format, ...);
extern signed int fscanf(FILE  *__restrict  __stream, const char  *__restrict  __format, ...) __asm__("" "__isoc99_fscanf");
extern signed int scanf(const char  *__restrict  __format, ...) __asm__("" "__isoc99_scanf");
extern signed int sscanf(const char  *__restrict  __s, const char  *__restrict  __format, ...) __asm__("" "__isoc99_sscanf") __attribute__((__nothrow__, __leaf__));
extern signed int vfscanf(FILE  *__restrict  __s, const char  *__restrict  __format, __gnuc_va_list  __arg);
extern signed int vscanf(const char  *__restrict  __format, __gnuc_va_list  __arg);
extern signed int vsscanf(const char  *__restrict  __s, const char  *__restrict  __format, __gnuc_va_list  __arg);
extern signed int vfscanf(FILE  *__restrict  __s, const char  *__restrict  __format, __gnuc_va_list  __arg) __asm__("" "__isoc99_vfscanf") __attribute__((__format__(__scanf__, 2, 0)));
extern signed int vscanf(const char  *__restrict  __format, __gnuc_va_list  __arg) __asm__("" "__isoc99_vscanf") __attribute__((__format__(__scanf__, 1, 0)));
extern signed int vsscanf(const char  *__restrict  __s, const char  *__restrict  __format, __gnuc_va_list  __arg) __asm__("" "__isoc99_vsscanf") __attribute__((__nothrow__, __leaf__)) __attribute__((__format__(__scanf__, 2, 0)));
extern signed int fgetc(FILE  * __stream);
extern signed int getc(FILE  * __stream);
extern signed int getchar(void);
extern signed int getc_unlocked(FILE  * __stream);
extern signed int getchar_unlocked(void);
extern signed int fputc(signed int  __c, FILE  * __stream);
extern signed int putc(signed int  __c, FILE  * __stream);
extern signed int putchar(signed int  __c);
extern signed int putc_unlocked(signed int  __c, FILE  * __stream);
extern signed int putchar_unlocked(signed int  __c);
extern char  *fgets(char  *__restrict  __s, signed int  __n, FILE  *__restrict  __stream);
extern __ssize_t __getdelim(char  * *__restrict  __lineptr, size_t  *__restrict  __n, signed int  __delimiter, FILE  *__restrict  __stream);
extern __ssize_t getdelim(char  * *__restrict  __lineptr, size_t  *__restrict  __n, signed int  __delimiter, FILE  *__restrict  __stream);
extern __ssize_t getline(char  * *__restrict  __lineptr, size_t  *__restrict  __n, FILE  *__restrict  __stream);
extern signed int fputs(const char  *__restrict  __s, FILE  *__restrict  __stream);
extern signed int puts(const char  * __s);
extern signed int ungetc(signed int  __c, FILE  * __stream);
extern size_t fread(void  *__restrict  __ptr, size_t  __size, size_t  __n, FILE  *__restrict  __stream);
extern size_t fwrite(const void  *__restrict  __ptr, size_t  __size, size_t  __n, FILE  *__restrict  __s);
extern signed int fseek(FILE  * __stream, signed long  __off, signed int  __whence);
extern signed long ftell(FILE  * __stream);
extern void rewind(FILE  * __stream);
extern signed int fseeko(FILE  * __stream, __off_t  __off, signed int  __whence);
extern __off_t ftello(FILE  * __stream);
extern signed int fgetpos(FILE  *__restrict  __stream, fpos_t  *__restrict  __pos);
extern signed int fsetpos(FILE  * __stream, const fpos_t  * __pos);
extern void clearerr(FILE  * __stream);
extern signed int feof(FILE  * __stream);
extern signed int ferror(FILE  * __stream);
extern void perror(const char  * __s);
extern signed int fileno(FILE  * __stream);
extern signed int pclose(FILE  * __stream);
extern FILE  *popen(const char  * __command, const char  * __modes);
extern char  *ctermid(char  * __s);
extern void flockfile(FILE  * __stream);
extern signed int ftrylockfile(FILE  * __stream);
extern void funlockfile(FILE  * __stream);
extern signed int __uflow(FILE  * );
extern signed int __overflow(FILE  * , signed int  );
extern void  *memcpy(void  *__restrict  __dest, const void  *__restrict  __src, size_t  __n);
extern void  *memmove(void  * __dest, const void  * __src, size_t  __n);
extern void  *memset(void  * __s, signed int  __c, size_t  __n);
extern signed int memcmp(const void  * __s1, const void  * __s2, size_t  __n);
extern signed int __memcmpeq(const void  * __s1, const void  * __s2, size_t  __n);
extern void  *memchr(const void  * __s, signed int  __c, size_t  __n);
extern char  *strcpy(char  *__restrict  __dest, const char  *__restrict  __src);
extern char  *strncpy(char  *__restrict  __dest, const char  *__restrict  __src, size_t  __n);
extern char  *strcat(char  *__restrict  __dest, const char  *__restrict  __src);
extern char  *strncat(char  *__restrict  __dest, const char  *__restrict  __src, size_t  __n);
extern signed int strcmp(const char  * __s1, const char  * __s2);
extern signed int strncmp(const char  * __s1, const char  * __s2, size_t  __n);
extern signed int strcoll(const char  * __s1, const char  * __s2);
extern size_t strxfrm(char  *__restrict  __dest, const char  *__restrict  __src, size_t  __n);
struct __locale_struct {
  struct __locale_data  *__locales[13];
  const unsigned short  *__ctype_b;
  const signed int  *__ctype_tolower;
  const signed int  *__ctype_toupper;
  const char  *__names[13];
  
};
typedef struct __locale_struct  *__locale_t;
typedef __locale_t locale_t;
extern signed int strcoll_l(const char  * __s1, const char  * __s2, locale_t  __l);
extern size_t strxfrm_l(char  * __dest, const char  * __src, size_t  __n, locale_t  __l);
extern char  *strdup(const char  * __s);
extern char  *strndup(const char  * __string, size_t  __n);
extern char  *strchr(const char  * __s, signed int  __c);
extern char  *strrchr(const char  * __s, signed int  __c);
extern size_t strcspn(const char  * __s, const char  * __reject);
extern size_t strspn(const char  * __s, const char  * __accept);
extern char  *strpbrk(const char  * __s, const char  * __accept);
extern char  *strstr(const char  * __haystack, const char  * __needle);
extern char  *strtok(char  *__restrict  __s, const char  *__restrict  __delim);
extern char  *__strtok_r(char  *__restrict  __s, const char  *__restrict  __delim, char  * *__restrict  __save_ptr);
extern char  *strtok_r(char  *__restrict  __s, const char  *__restrict  __delim, char  * *__restrict  __save_ptr);
extern size_t strlen(const char  * __s);
extern size_t strnlen(const char  * __string, size_t  __maxlen);
extern char  *strerror(signed int  __errnum);
extern signed int strerror_r(signed int  __errnum, char  * __buf, size_t  __buflen) __asm__("" "__xpg_strerror_r") __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2))) __attribute__((__access__(__write_only__, 2, 3)));
extern char  *strerror_l(signed int  __errnum, locale_t  __l);
extern char  *strsignal(signed int  __sig);
extern char  *__stpcpy(char  *__restrict  __dest, const char  *__restrict  __src);
extern char  *stpcpy(char  *__restrict  __dest, const char  *__restrict  __src);
extern char  *__stpncpy(char  *__restrict  __dest, const char  *__restrict  __src, size_t  __n);
extern char  *stpncpy(char  *__restrict  __dest, const char  *__restrict  __src, size_t  __n);
typedef __useconds_t useconds_t;
extern signed int access(const char  * __name, signed int  __type);
extern signed int faccessat(signed int  __fd, const char  * __file, signed int  __type, signed int  __flag);
extern __off_t lseek(signed int  __fd, __off_t  __offset, signed int  __whence);
extern signed int close(signed int  __fd);
extern ssize_t read(signed int  __fd, void  * __buf, size_t  __nbytes);
extern ssize_t write(signed int  __fd, const void  * __buf, size_t  __n);
extern ssize_t pread(signed int  __fd, void  * __buf, size_t  __nbytes, __off_t  __offset);
extern ssize_t pwrite(signed int  __fd, const void  * __buf, size_t  __n, __off_t  __offset);
extern signed int pipe(signed int  __pipedes[2]);
extern unsigned int alarm(unsigned int  __seconds);
extern unsigned int sleep(unsigned int  __seconds);
extern signed int pause(void);
extern signed int chown(const char  * __file, __uid_t  __owner, __gid_t  __group);
extern signed int fchown(signed int  __fd, __uid_t  __owner, __gid_t  __group);
extern signed int lchown(const char  * __file, __uid_t  __owner, __gid_t  __group);
extern signed int fchownat(signed int  __fd, const char  * __file, __uid_t  __owner, __gid_t  __group, signed int  __flag);
extern signed int chdir(const char  * __path);
extern signed int fchdir(signed int  __fd);
extern char  *getcwd(char  * __buf, size_t  __size);
extern signed int dup(signed int  __fd);
extern signed int dup2(signed int  __fd, signed int  __fd2);
extern char  * *__environ;
extern signed int execve(const char  * __path, char  *const  __argv[], char  *const  __envp[]);
extern signed int fexecve(signed int  __fd, char  *const  __argv[], char  *const  __envp[]);
extern signed int execv(const char  * __path, char  *const  __argv[]);
extern signed int execle(const char  * __path, const char  * __arg, ...);
extern signed int execl(const char  * __path, const char  * __arg, ...);
extern signed int execvp(const char  * __file, char  *const  __argv[]);
extern signed int execlp(const char  * __file, const char  * __arg, ...);
extern void _exit(signed int  __status);
enum  {
  _PC_LINK_MAX,
  _PC_MAX_CANON,
  _PC_MAX_INPUT,
  _PC_NAME_MAX,
  _PC_PATH_MAX,
  _PC_PIPE_BUF,
  _PC_CHOWN_RESTRICTED,
  _PC_NO_TRUNC,
  _PC_VDISABLE,
  _PC_SYNC_IO,
  _PC_ASYNC_IO,
  _PC_PRIO_IO,
  _PC_SOCK_MAXBUF,
  _PC_FILESIZEBITS,
  _PC_REC_INCR_XFER_SIZE,
  _PC_REC_MAX_XFER_SIZE,
  _PC_REC_MIN_XFER_SIZE,
  _PC_REC_XFER_ALIGN,
  _PC_ALLOC_SIZE_MIN,
  _PC_SYMLINK_MAX,
  _PC_2_SYMLINKS
};
enum  {
  _SC_ARG_MAX,
  _SC_CHILD_MAX,
  _SC_CLK_TCK,
  _SC_NGROUPS_MAX,
  _SC_OPEN_MAX,
  _SC_STREAM_MAX,
  _SC_TZNAME_MAX,
  _SC_JOB_CONTROL,
  _SC_SAVED_IDS,
  _SC_REALTIME_SIGNALS,
  _SC_PRIORITY_SCHEDULING,
  _SC_TIMERS,
  _SC_ASYNCHRONOUS_IO,
  _SC_PRIORITIZED_IO,
  _SC_SYNCHRONIZED_IO,
  _SC_FSYNC,
  _SC_MAPPED_FILES,
  _SC_MEMLOCK,
  _SC_MEMLOCK_RANGE,
  _SC_MEMORY_PROTECTION,
  _SC_MESSAGE_PASSING,
  _SC_SEMAPHORES,
  _SC_SHARED_MEMORY_OBJECTS,
  _SC_AIO_LISTIO_MAX,
  _SC_AIO_MAX,
  _SC_AIO_PRIO_DELTA_MAX,
  _SC_DELAYTIMER_MAX,
  _SC_MQ_OPEN_MAX,
  _SC_MQ_PRIO_MAX,
  _SC_VERSION,
  _SC_PAGESIZE,
  _SC_RTSIG_MAX,
  _SC_SEM_NSEMS_MAX,
  _SC_SEM_VALUE_MAX,
  _SC_SIGQUEUE_MAX,
  _SC_TIMER_MAX,
  _SC_BC_BASE_MAX,
  _SC_BC_DIM_MAX,
  _SC_BC_SCALE_MAX,
  _SC_BC_STRING_MAX,
  _SC_COLL_WEIGHTS_MAX,
  _SC_EQUIV_CLASS_MAX,
  _SC_EXPR_NEST_MAX,
  _SC_LINE_MAX,
  _SC_RE_DUP_MAX,
  _SC_CHARCLASS_NAME_MAX,
  _SC_2_VERSION,
  _SC_2_C_BIND,
  _SC_2_C_DEV,
  _SC_2_FORT_DEV,
  _SC_2_FORT_RUN,
  _SC_2_SW_DEV,
  _SC_2_LOCALEDEF,
  _SC_PII,
  _SC_PII_XTI,
  _SC_PII_SOCKET,
  _SC_PII_INTERNET,
  _SC_PII_OSI,
  _SC_POLL,
  _SC_SELECT,
  _SC_UIO_MAXIOV,
  _SC_IOV_MAX = (_SC_UIO_MAXIOV),
  _SC_PII_INTERNET_STREAM,
  _SC_PII_INTERNET_DGRAM,
  _SC_PII_OSI_COTS,
  _SC_PII_OSI_CLTS,
  _SC_PII_OSI_M,
  _SC_T_IOV_MAX,
  _SC_THREADS,
  _SC_THREAD_SAFE_FUNCTIONS,
  _SC_GETGR_R_SIZE_MAX,
  _SC_GETPW_R_SIZE_MAX,
  _SC_LOGIN_NAME_MAX,
  _SC_TTY_NAME_MAX,
  _SC_THREAD_DESTRUCTOR_ITERATIONS,
  _SC_THREAD_KEYS_MAX,
  _SC_THREAD_STACK_MIN,
  _SC_THREAD_THREADS_MAX,
  _SC_THREAD_ATTR_STACKADDR,
  _SC_THREAD_ATTR_STACKSIZE,
  _SC_THREAD_PRIORITY_SCHEDULING,
  _SC_THREAD_PRIO_INHERIT,
  _SC_THREAD_PRIO_PROTECT,
  _SC_THREAD_PROCESS_SHARED,
  _SC_NPROCESSORS_CONF,
  _SC_NPROCESSORS_ONLN,
  _SC_PHYS_PAGES,
  _SC_AVPHYS_PAGES,
  _SC_ATEXIT_MAX,
  _SC_PASS_MAX,
  _SC_XOPEN_VERSION,
  _SC_XOPEN_XCU_VERSION,
  _SC_XOPEN_UNIX,
  _SC_XOPEN_CRYPT,
  _SC_XOPEN_ENH_I18N,
  _SC_XOPEN_SHM,
  _SC_2_CHAR_TERM,
  _SC_2_C_VERSION,
  _SC_2_UPE,
  _SC_XOPEN_XPG2,
  _SC_XOPEN_XPG3,
  _SC_XOPEN_XPG4,
  _SC_CHAR_BIT,
  _SC_CHAR_MAX,
  _SC_CHAR_MIN,
  _SC_INT_MAX,
  _SC_INT_MIN,
  _SC_LONG_BIT,
  _SC_WORD_BIT,
  _SC_MB_LEN_MAX,
  _SC_NZERO,
  _SC_SSIZE_MAX,
  _SC_SCHAR_MAX,
  _SC_SCHAR_MIN,
  _SC_SHRT_MAX,
  _SC_SHRT_MIN,
  _SC_UCHAR_MAX,
  _SC_UINT_MAX,
  _SC_ULONG_MAX,
  _SC_USHRT_MAX,
  _SC_NL_ARGMAX,
  _SC_NL_LANGMAX,
  _SC_NL_MSGMAX,
  _SC_NL_NMAX,
  _SC_NL_SETMAX,
  _SC_NL_TEXTMAX,
  _SC_XBS5_ILP32_OFF32,
  _SC_XBS5_ILP32_OFFBIG,
  _SC_XBS5_LP64_OFF64,
  _SC_XBS5_LPBIG_OFFBIG,
  _SC_XOPEN_LEGACY,
  _SC_XOPEN_REALTIME,
  _SC_XOPEN_REALTIME_THREADS,
  _SC_ADVISORY_INFO,
  _SC_BARRIERS,
  _SC_BASE,
  _SC_C_LANG_SUPPORT,
  _SC_C_LANG_SUPPORT_R,
  _SC_CLOCK_SELECTION,
  _SC_CPUTIME,
  _SC_THREAD_CPUTIME,
  _SC_DEVICE_IO,
  _SC_DEVICE_SPECIFIC,
  _SC_DEVICE_SPECIFIC_R,
  _SC_FD_MGMT,
  _SC_FIFO,
  _SC_PIPE,
  _SC_FILE_ATTRIBUTES,
  _SC_FILE_LOCKING,
  _SC_FILE_SYSTEM,
  _SC_MONOTONIC_CLOCK,
  _SC_MULTI_PROCESS,
  _SC_SINGLE_PROCESS,
  _SC_NETWORKING,
  _SC_READER_WRITER_LOCKS,
  _SC_SPIN_LOCKS,
  _SC_REGEXP,
  _SC_REGEX_VERSION,
  _SC_SHELL,
  _SC_SIGNALS,
  _SC_SPAWN,
  _SC_SPORADIC_SERVER,
  _SC_THREAD_SPORADIC_SERVER,
  _SC_SYSTEM_DATABASE,
  _SC_SYSTEM_DATABASE_R,
  _SC_TIMEOUTS,
  _SC_TYPED_MEMORY_OBJECTS,
  _SC_USER_GROUPS,
  _SC_USER_GROUPS_R,
  _SC_2_PBS,
  _SC_2_PBS_ACCOUNTING,
  _SC_2_PBS_LOCATE,
  _SC_2_PBS_MESSAGE,
  _SC_2_PBS_TRACK,
  _SC_SYMLOOP_MAX,
  _SC_STREAMS,
  _SC_2_PBS_CHECKPOINT,
  _SC_V6_ILP32_OFF32,
  _SC_V6_ILP32_OFFBIG,
  _SC_V6_LP64_OFF64,
  _SC_V6_LPBIG_OFFBIG,
  _SC_HOST_NAME_MAX,
  _SC_TRACE,
  _SC_TRACE_EVENT_FILTER,
  _SC_TRACE_INHERIT,
  _SC_TRACE_LOG,
  _SC_LEVEL1_ICACHE_SIZE,
  _SC_LEVEL1_ICACHE_ASSOC,
  _SC_LEVEL1_ICACHE_LINESIZE,
  _SC_LEVEL1_DCACHE_SIZE,
  _SC_LEVEL1_DCACHE_ASSOC,
  _SC_LEVEL1_DCACHE_LINESIZE,
  _SC_LEVEL2_CACHE_SIZE,
  _SC_LEVEL2_CACHE_ASSOC,
  _SC_LEVEL2_CACHE_LINESIZE,
  _SC_LEVEL3_CACHE_SIZE,
  _SC_LEVEL3_CACHE_ASSOC,
  _SC_LEVEL3_CACHE_LINESIZE,
  _SC_LEVEL4_CACHE_SIZE,
  _SC_LEVEL4_CACHE_ASSOC,
  _SC_LEVEL4_CACHE_LINESIZE,
  _SC_IPV6 = ((_SC_LEVEL1_ICACHE_SIZE) + 50),
  _SC_RAW_SOCKETS,
  _SC_V7_ILP32_OFF32,
  _SC_V7_ILP32_OFFBIG,
  _SC_V7_LP64_OFF64,
  _SC_V7_LPBIG_OFFBIG,
  _SC_SS_REPL_MAX,
  _SC_TRACE_EVENT_NAME_MAX,
  _SC_TRACE_NAME_MAX,
  _SC_TRACE_SYS_MAX,
  _SC_TRACE_USER_EVENT_MAX,
  _SC_XOPEN_STREAMS,
  _SC_THREAD_ROBUST_PRIO_INHERIT,
  _SC_THREAD_ROBUST_PRIO_PROTECT,
  _SC_MINSIGSTKSZ,
  _SC_SIGSTKSZ
};
enum  {
  _CS_PATH,
  _CS_V6_WIDTH_RESTRICTED_ENVS,
  _CS_GNU_LIBC_VERSION,
  _CS_GNU_LIBPTHREAD_VERSION,
  _CS_V5_WIDTH_RESTRICTED_ENVS,
  _CS_V7_WIDTH_RESTRICTED_ENVS,
  _CS_LFS_CFLAGS = 1000,
  _CS_LFS_LDFLAGS,
  _CS_LFS_LIBS,
  _CS_LFS_LINTFLAGS,
  _CS_LFS64_CFLAGS,
  _CS_LFS64_LDFLAGS,
  _CS_LFS64_LIBS,
  _CS_LFS64_LINTFLAGS,
  _CS_XBS5_ILP32_OFF32_CFLAGS = 1100,
  _CS_XBS5_ILP32_OFF32_LDFLAGS,
  _CS_XBS5_ILP32_OFF32_LIBS,
  _CS_XBS5_ILP32_OFF32_LINTFLAGS,
  _CS_XBS5_ILP32_OFFBIG_CFLAGS,
  _CS_XBS5_ILP32_OFFBIG_LDFLAGS,
  _CS_XBS5_ILP32_OFFBIG_LIBS,
  _CS_XBS5_ILP32_OFFBIG_LINTFLAGS,
  _CS_XBS5_LP64_OFF64_CFLAGS,
  _CS_XBS5_LP64_OFF64_LDFLAGS,
  _CS_XBS5_LP64_OFF64_LIBS,
  _CS_XBS5_LP64_OFF64_LINTFLAGS,
  _CS_XBS5_LPBIG_OFFBIG_CFLAGS,
  _CS_XBS5_LPBIG_OFFBIG_LDFLAGS,
  _CS_XBS5_LPBIG_OFFBIG_LIBS,
  _CS_XBS5_LPBIG_OFFBIG_LINTFLAGS,
  _CS_POSIX_V6_ILP32_OFF32_CFLAGS,
  _CS_POSIX_V6_ILP32_OFF32_LDFLAGS,
  _CS_POSIX_V6_ILP32_OFF32_LIBS,
  _CS_POSIX_V6_ILP32_OFF32_LINTFLAGS,
  _CS_POSIX_V6_ILP32_OFFBIG_CFLAGS,
  _CS_POSIX_V6_ILP32_OFFBIG_LDFLAGS,
  _CS_POSIX_V6_ILP32_OFFBIG_LIBS,
  _CS_POSIX_V6_ILP32_OFFBIG_LINTFLAGS,
  _CS_POSIX_V6_LP64_OFF64_CFLAGS,
  _CS_POSIX_V6_LP64_OFF64_LDFLAGS,
  _CS_POSIX_V6_LP64_OFF64_LIBS,
  _CS_POSIX_V6_LP64_OFF64_LINTFLAGS,
  _CS_POSIX_V6_LPBIG_OFFBIG_CFLAGS,
  _CS_POSIX_V6_LPBIG_OFFBIG_LDFLAGS,
  _CS_POSIX_V6_LPBIG_OFFBIG_LIBS,
  _CS_POSIX_V6_LPBIG_OFFBIG_LINTFLAGS,
  _CS_POSIX_V7_ILP32_OFF32_CFLAGS,
  _CS_POSIX_V7_ILP32_OFF32_LDFLAGS,
  _CS_POSIX_V7_ILP32_OFF32_LIBS,
  _CS_POSIX_V7_ILP32_OFF32_LINTFLAGS,
  _CS_POSIX_V7_ILP32_OFFBIG_CFLAGS,
  _CS_POSIX_V7_ILP32_OFFBIG_LDFLAGS,
  _CS_POSIX_V7_ILP32_OFFBIG_LIBS,
  _CS_POSIX_V7_ILP32_OFFBIG_LINTFLAGS,
  _CS_POSIX_V7_LP64_OFF64_CFLAGS,
  _CS_POSIX_V7_LP64_OFF64_LDFLAGS,
  _CS_POSIX_V7_LP64_OFF64_LIBS,
  _CS_POSIX_V7_LP64_OFF64_LINTFLAGS,
  _CS_POSIX_V7_LPBIG_OFFBIG_CFLAGS,
  _CS_POSIX_V7_LPBIG_OFFBIG_LDFLAGS,
  _CS_POSIX_V7_LPBIG_OFFBIG_LIBS,
  _CS_POSIX_V7_LPBIG_OFFBIG_LINTFLAGS,
  _CS_V6_ENV,
  _CS_V7_ENV
};
extern signed long pathconf(const char  * __path, signed int  __name);
extern signed long fpathconf(signed int  __fd, signed int  __name);
extern signed long sysconf(signed int  __name);
extern size_t confstr(signed int  __name, char  * __buf, size_t  __len);
extern __pid_t getpid(void);
extern __pid_t getppid(void);
extern __pid_t getpgrp(void);
extern __pid_t __getpgid(__pid_t  __pid);
extern __pid_t getpgid(__pid_t  __pid);
extern signed int setpgid(__pid_t  __pid, __pid_t  __pgid);
extern __pid_t setsid(void);
extern __pid_t getsid(__pid_t  __pid);
extern __uid_t getuid(void);
extern __uid_t geteuid(void);
extern __gid_t getgid(void);
extern __gid_t getegid(void);
extern signed int getgroups(signed int  __size, __gid_t  __list[]);
extern signed int setuid(__uid_t  __uid);
extern signed int seteuid(__uid_t  __uid);
extern signed int setgid(__gid_t  __gid);
extern signed int setegid(__gid_t  __gid);
extern __pid_t fork(void);
extern char  *ttyname(signed int  __fd);
extern signed int ttyname_r(signed int  __fd, char  * __buf, size_t  __buflen);
extern signed int isatty(signed int  __fd);
extern signed int link(const char  * __from, const char  * __to);
extern signed int linkat(signed int  __fromfd, const char  * __from, signed int  __tofd, const char  * __to, signed int  __flags);
extern signed int symlink(const char  * __from, const char  * __to);
extern ssize_t readlink(const char  *__restrict  __path, char  *__restrict  __buf, size_t  __len);
extern signed int symlinkat(const char  * __from, signed int  __tofd, const char  * __to);
extern ssize_t readlinkat(signed int  __fd, const char  *__restrict  __path, char  *__restrict  __buf, size_t  __len);
extern signed int unlink(const char  * __name);
extern signed int unlinkat(signed int  __fd, const char  * __name, signed int  __flag);
extern signed int rmdir(const char  * __path);
extern __pid_t tcgetpgrp(signed int  __fd);
extern signed int tcsetpgrp(signed int  __fd, __pid_t  __pgrp_id);
extern char  *getlogin(void);
extern signed int getlogin_r(char  * __name, size_t  __name_len);
extern char  *optarg;
extern signed int optind;
extern signed int opterr;
extern signed int optopt;
extern signed int getopt(signed int  ___argc, char  *const  * ___argv, const char  * __shortopts);
extern signed int getopt(signed int  ___argc, char  *const  * ___argv, const char  * __shortopts) __asm__("" "__posix_getopt") __attribute__((__nothrow__, __leaf__));
extern signed int gethostname(char  * __name, size_t  __len);
extern signed int fsync(signed int  __fd);
extern signed int truncate(const char  * __file, __off_t  __length);
extern signed int ftruncate(signed int  __fd, __off_t  __length);
extern signed int fdatasync(signed int  __fildes);
static _Bool  safemult_sizet(size_t  a, size_t  b, size_t  * res)
{

  ;
  {
    size_t tmp = ((a) * (b));
    if (((b) && ((((tmp) / (b)) != (a)))))
    {
      return 0;
    } else {
      ;
    }
    ((*(res)) = (tmp));
    return 1;
  }
}
void  array_init(array  * a)
{

  ;
  {
    (((a)->mem) = (((void *)0)));
    (((a)->allocated) = 0);
    (((a)->used) = 0);
  }
}
void  * array_alloc(array  * a, size_t  size, size_t  pos)
{

  ;
  {
    size_t alloc, pos_plus1 = ((pos) + 1);
    char  *tmp;
    (((void)(0)));
    if ((((pos_plus1) == 0) || (!((safemult_sizet)((size), (pos_plus1), (&(alloc)))))))
    {
      return (((void *)0));
    } else {
      ;
    }
    if ((((a)->allocated) < (alloc)))
    {
      {
        ((tmp) = ((realloc)(((a)->mem), (alloc))));
        if ((!(tmp)))
        {
          return (((void *)0));
        } else {
          ;
        }
        (((a)->mem) = (tmp));
        (((a)->allocated) = (alloc));
        ((memset)((((a)->mem) + ((a)->used)), 0, (((a)->allocated) - ((a)->used))));
        (((a)->used) = (alloc));
      }
    } else {
      ;
    }
    (((void)(0)));
    return (((a)->mem) + (((pos) * (size))));
  }
}
size_t  array_length(const array  *const  a, size_t  membersize)
{

  ;
  {
    (((void)(0)));
    if (((!(((a))->mem))))
    {
      return 0;
    } else {
      ;
    }
    (((void)(0)));
    return ((membersize) ? (((a)->used) / (membersize)) : 0);
  }
}
_Bool  array_copy(array  * dest, const array  *const  src)
{

  ;
  {
    if (((!(((src))->mem))))
    {
      return 0;
    } else {
      ;
    }
    (((void)(0)));
    return ((array_copyb)((dest), ((src)->mem), ((src)->used)));
  }
}
_Bool  array_copyb(array  * dest, const char  * src, size_t  len)
{

  ;
  {
    if (((!(src)) || (!(dest))))
    {
      return 0;
    } else {
      ;
    }
    ((array_trunc)((dest)));
    return ((array_catb)((dest), (src), (len)));
  }
}
_Bool  array_copys(array  * dest, const char  * src)
{

  ;
  {
    return ((array_copyb)((dest), (src), ((strlen)((src)))));
  }
}
_Bool  array_catb(array  * dest, const char  * src, size_t  len)
{

  ;
  {
    size_t tmp;
    size_t used;
    char  *ptr;
    if ((!(len)))
    {
      return 1;
    } else {
      ;
    }
    if (((!(src)) || (!(dest))))
    {
      return 0;
    } else {
      ;
    }
    ((used) = ((dest)->used));
    ((tmp) = ((used) + (len)));
    if ((((tmp) < (used)) || ((tmp) < (len))))
    {
      return 0;
    } else {
      ;
    }
    if ((!((array_alloc)((dest), 1, (tmp)))))
    {
      return 0;
    } else {
      ;
    }
    ((ptr) = ((dest)->mem));
    (((void)(0)));
    ((memcpy)(((ptr) + (used)), (src), (len)));
    (((dest)->used) = (tmp));
    return 1;
  }
}
_Bool  array_cats(array  * dest, const char  * src)
{

  ;
  {
    return ((array_catb)((dest), (src), ((strlen)((src)))));
  }
}
_Bool  array_cat0(array  * a)
{

  ;
  {
    return ((array_catb)((a), "", 1));
  }
}
_Bool  array_cat0_temporary(array  * a)
{

  ;
  {
    char  *endpos = ((char *)({
      void  *_tmp10 = ((array_alloc)((a), 1, ((((a))->used))));
      ({
        if (((_tmp10) == 0))
        {
          ((fprintf)((stderr), "array.xc:194:25:ERROR: attempted cast of NULL to nonnull\\n"));
          ((exit)(255));
        } else {
          ;
        }
        (_tmp10); })
      ; })
    );
    if ((!(endpos)))
    {
      return 0;
    } else {
      ;
    }
    ((*(endpos)) = '\0');
    return 1;
  }
}
_Bool  array_cat(array  * dest, const array  *const  src)
{

  ;
  {
    if (((!(((src))->mem))))
    {
      return 0;
    } else {
      ;
    }
    return ((array_catb)((dest), ((src)->mem), ((src)->used)));
  }
}
void  * array_get(array  * a, size_t  membersize, size_t  pos)
{

  ;
  {
    size_t totalsize;
    size_t posplus1 = ((pos) + 1);
    (((void)(0)));
    if (((!(posplus1)) || ((!(((a))->mem)))))
    {
      return (((void *)0));
    } else {
      ;
    }
    if ((!((safemult_sizet)((posplus1), (membersize), (&(totalsize))))))
    {
      return (((void *)0));
    } else {
      ;
    }
    if ((((a)->allocated) < (totalsize)))
    {
      return (((void *)0));
    } else {
      ;
    }
    ((totalsize) = ((pos) * (membersize)));
    return (((a)->mem) + (totalsize));
  }
}
void  array_free(array  * a)
{

  ;
  {
    ((free)(((a)->mem)));
    (((a)->mem) = (((void *)0)));
    (((a)->allocated) = 0);
    (((a)->used) = 0);
  }
}
void  array_free_wipe(array  * a)
{

  ;
  {
    size_t bytes = ((a)->allocated);
    if ((bytes))
    {
      ((memset)(((a)->mem), 0, (bytes)));
    } else {
      ;
    }
    ((array_free)((a)));
  }
}
void  * array_start(const array  *const  a)
{

  ;
  {
    return ((a)->mem);
  }
}
void  array_trunc(array  * a)
{

  ;
  {
    (((a)->used) = 0);
  }
}
void  array_truncate(array  * a, size_t  membersize, size_t  len)
{

  ;
  {
    size_t newlen;
    if ((!((safemult_sizet)((membersize), (len), (&(newlen))))))
    {
      return ;
    } else {
      ;
    }
    if (((newlen) <= ((a)->allocated)))
    {
      (((a)->used) = (newlen));
    } else {
      ;
    }
  }
}
void  array_moveleft(array  * a, size_t  membersize, size_t  pos)
{

  ;
  {
    size_t bytepos;
    (((void)(0)));
    if ((!((safemult_sizet)((membersize), (pos), (&(bytepos))))))
    {
      {
        (((a)->used) = 0);
        return ;
      }
    } else {
      ;
    }
    if ((!(bytepos)))
    {
      return ;
    } else {
      ;
    }
    if ((((a)->used) <= (bytepos)))
    {
      {
        (((a)->used) = 0);
        return ;
      }
    } else {
      ;
    }
    (((a)->used) -= (bytepos));
    ((memmove)(((a)->mem), (((a)->mem) + (bytepos)), ((a)->used)));
  }
}

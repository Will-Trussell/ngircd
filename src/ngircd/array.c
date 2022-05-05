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
typedef __ssize_t ssize_t;
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
typedef __blkcnt_t blkcnt_t;
typedef __fsblkcnt_t fsblkcnt_t;
typedef __fsfilcnt_t fsfilcnt_t;
typedef signed long ptrdiff_t;
typedef signed int wchar_t;
typedef struct anon__usr_lib_gcc_x86_64_pc_linux_gnu_11_2_1_include_stddef_h_415_8 {
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
extern intmax_t imaxabs(intmax_t  __n) __attribute__((__nothrow__, __leaf__)) __attribute__((__const__));
extern imaxdiv_t imaxdiv(intmax_t  __numer, intmax_t  __denom) __attribute__((__nothrow__, __leaf__)) __attribute__((__const__));
extern intmax_t strtoimax(const char  *__restrict  __nptr, char  * *__restrict  __endptr, signed int  __base) __attribute__((__nothrow__, __leaf__));
extern uintmax_t strtoumax(const char  *__restrict  __nptr, char  * *__restrict  __endptr, signed int  __base) __attribute__((__nothrow__, __leaf__));
extern intmax_t wcstoimax(const __gwchar_t  *__restrict  __nptr, __gwchar_t  * *__restrict  __endptr, signed int  __base) __attribute__((__nothrow__, __leaf__));
extern uintmax_t wcstoumax(const __gwchar_t  *__restrict  __nptr, __gwchar_t  * *__restrict  __endptr, signed int  __base) __attribute__((__nothrow__, __leaf__));
typedef void POINTER;
typedef uint8_t UINT8;
typedef uint16_t UINT16;
typedef uint32_t UINT32;
extern size_t strlcat(char  * dst, const char  * src, size_t  size);
extern size_t strlcpy(char  * dst, const char  * src, size_t  size);
typedef struct anon___src_ngircd_array_h_22_8 {
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
typedef struct anon__usr_include_stdlib_h_58_8 {
  signed int quot;
  signed int rem;
  
} div_t;
typedef struct anon__usr_include_stdlib_h_66_8 {
  signed long quot;
  signed long rem;
  
} ldiv_t;
typedef struct anon__usr_include_stdlib_h_76_22 {
  signed long long quot;
  signed long long rem;
  
} lldiv_t;
extern size_t __ctype_get_mb_cur_max(void) __attribute__((__nothrow__, __leaf__));
extern double atof(const char  * __nptr) __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__)) __attribute__((__nonnull__(1)));
extern signed int atoi(const char  * __nptr) __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__)) __attribute__((__nonnull__(1)));
extern signed long atol(const char  * __nptr) __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__)) __attribute__((__nonnull__(1)));
extern signed long long atoll(const char  * __nptr) __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__)) __attribute__((__nonnull__(1)));
extern double strtod(const char  *__restrict  __nptr, char  * *__restrict  __endptr) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern float strtof(const char  *__restrict  __nptr, char  * *__restrict  __endptr) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern long double strtold(const char  *__restrict  __nptr, char  * *__restrict  __endptr) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern signed long strtol(const char  *__restrict  __nptr, char  * *__restrict  __endptr, signed int  __base) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern unsigned long strtoul(const char  *__restrict  __nptr, char  * *__restrict  __endptr, signed int  __base) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern signed long long strtoll(const char  *__restrict  __nptr, char  * *__restrict  __endptr, signed int  __base) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern unsigned long long strtoull(const char  *__restrict  __nptr, char  * *__restrict  __endptr, signed int  __base) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern signed int rand(void) __attribute__((__nothrow__, __leaf__));
extern void srand(unsigned int  __seed) __attribute__((__nothrow__, __leaf__));
extern void  *malloc(size_t  __size) __attribute__((__nothrow__, __leaf__)) __attribute__((__malloc__)) __attribute__((__alloc_size__(1)));
extern void  *calloc(size_t  __nmemb, size_t  __size) __attribute__((__nothrow__, __leaf__)) __attribute__((__malloc__)) __attribute__((__alloc_size__(1, 2)));
extern void  *realloc(void  * __ptr, size_t  __size) __attribute__((__nothrow__, __leaf__)) __attribute__((__warn_unused_result__)) __attribute__((__alloc_size__(2)));
extern void free(void  * __ptr) __attribute__((__nothrow__, __leaf__));
extern void  *aligned_alloc(size_t  __alignment, size_t  __size) __attribute__((__nothrow__, __leaf__)) __attribute__((__malloc__)) __attribute__((__alloc_size__(2)));
extern void abort(void) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
extern signed int atexit(void ( * __func)(void)) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern signed int at_quick_exit(void ( * __func)(void)) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern void exit(signed int  __status) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
extern void quick_exit(signed int  __status) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
extern void _Exit(signed int  __status) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
extern char  *getenv(const char  * __name) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern signed int system(const char  * __command);
typedef signed int ( *__compar_fn_t)(const void  * , const void  * );
extern void  *bsearch(const void  * __key, const void  * __base, size_t  __nmemb, size_t  __size, __compar_fn_t  __compar) __attribute__((__nonnull__(1, 2, 5)));
extern void qsort(void  * __base, size_t  __nmemb, size_t  __size, __compar_fn_t  __compar) __attribute__((__nonnull__(1, 4)));
extern signed int abs(signed int  __x) __attribute__((__nothrow__, __leaf__)) __attribute__((__const__));
extern signed long labs(signed long  __x) __attribute__((__nothrow__, __leaf__)) __attribute__((__const__));
extern signed long long llabs(signed long long  __x) __attribute__((__nothrow__, __leaf__)) __attribute__((__const__));
extern div_t div(signed int  __numer, signed int  __denom) __attribute__((__nothrow__, __leaf__)) __attribute__((__const__));
extern ldiv_t ldiv(signed long  __numer, signed long  __denom) __attribute__((__nothrow__, __leaf__)) __attribute__((__const__));
extern lldiv_t lldiv(signed long long  __numer, signed long long  __denom) __attribute__((__nothrow__, __leaf__)) __attribute__((__const__));
extern signed int mblen(const char  * __s, size_t  __n) __attribute__((__nothrow__, __leaf__));
extern signed int mbtowc(wchar_t  *__restrict  __pwc, const char  *__restrict  __s, size_t  __n) __attribute__((__nothrow__, __leaf__));
extern signed int wctomb(char  * __s, wchar_t  __wchar) __attribute__((__nothrow__, __leaf__));
extern size_t mbstowcs(wchar_t  *__restrict  __pwcs, const char  *__restrict  __s, size_t  __n) __attribute__((__nothrow__, __leaf__)) __attribute__((__access__(__read_only__, 2)));
extern size_t wcstombs(char  *__restrict  __s, const wchar_t  *__restrict  __pwcs, size_t  __n) __attribute__((__nothrow__, __leaf__)) __attribute__((__access__(__write_only__, 1, 3))) __attribute__((__access__(__read_only__, 2)));
extern void  *memcpy(void  *__restrict  __dest, const void  *__restrict  __src, size_t  __n) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern void  *memmove(void  * __dest, const void  * __src, size_t  __n) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern void  *memset(void  * __s, signed int  __c, size_t  __n) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern signed int memcmp(const void  * __s1, const void  * __s2, size_t  __n) __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__)) __attribute__((__nonnull__(1, 2)));
extern void  *memchr(const void  * __s, signed int  __c, size_t  __n) __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__)) __attribute__((__nonnull__(1)));
extern char  *strcpy(char  *__restrict  __dest, const char  *__restrict  __src) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern char  *strncpy(char  *__restrict  __dest, const char  *__restrict  __src, size_t  __n) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern char  *strcat(char  *__restrict  __dest, const char  *__restrict  __src) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern char  *strncat(char  *__restrict  __dest, const char  *__restrict  __src, size_t  __n) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern signed int strcmp(const char  * __s1, const char  * __s2) __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__)) __attribute__((__nonnull__(1, 2)));
extern signed int strncmp(const char  * __s1, const char  * __s2, size_t  __n) __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__)) __attribute__((__nonnull__(1, 2)));
extern signed int strcoll(const char  * __s1, const char  * __s2) __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__)) __attribute__((__nonnull__(1, 2)));
extern size_t strxfrm(char  *__restrict  __dest, const char  *__restrict  __src, size_t  __n) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2))) __attribute__((__access__(__write_only__, 1, 3)));
extern char  *strchr(const char  * __s, signed int  __c) __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__)) __attribute__((__nonnull__(1)));
extern char  *strrchr(const char  * __s, signed int  __c) __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__)) __attribute__((__nonnull__(1)));
extern size_t strcspn(const char  * __s, const char  * __reject) __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__)) __attribute__((__nonnull__(1, 2)));
extern size_t strspn(const char  * __s, const char  * __accept) __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__)) __attribute__((__nonnull__(1, 2)));
extern char  *strpbrk(const char  * __s, const char  * __accept) __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__)) __attribute__((__nonnull__(1, 2)));
extern char  *strstr(const char  * __haystack, const char  * __needle) __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__)) __attribute__((__nonnull__(1, 2)));
extern char  *strtok(char  *__restrict  __s, const char  *__restrict  __delim) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2)));
extern char  *__strtok_r(char  *__restrict  __s, const char  *__restrict  __delim, char  * *__restrict  __save_ptr) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2, 3)));
extern char  *strtok_r(char  *__restrict  __s, const char  *__restrict  __delim, char  * *__restrict  __save_ptr) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2, 3)));
extern size_t strlen(const char  * __s) __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__)) __attribute__((__nonnull__(1)));
extern char  *strerror(signed int  __errnum) __attribute__((__nothrow__, __leaf__));
extern signed int access(const char  * __name, signed int  __type) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern __off_t lseek(signed int  __fd, __off_t  __offset, signed int  __whence) __attribute__((__nothrow__, __leaf__));
extern signed int close(signed int  __fd);
extern ssize_t read(signed int  __fd, void  * __buf, size_t  __nbytes) __attribute__((__access__(__write_only__, 2, 3)));
extern ssize_t write(signed int  __fd, const void  * __buf, size_t  __n) __attribute__((__access__(__read_only__, 2, 3)));
extern signed int pipe(signed int  __pipedes[2]) __attribute__((__nothrow__, __leaf__));
extern unsigned int alarm(unsigned int  __seconds) __attribute__((__nothrow__, __leaf__));
extern unsigned int sleep(unsigned int  __seconds);
extern signed int pause(void);
extern signed int chown(const char  * __file, __uid_t  __owner, __gid_t  __group) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern signed int chdir(const char  * __path) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern char  *getcwd(char  * __buf, size_t  __size) __attribute__((__nothrow__, __leaf__));
extern signed int dup(signed int  __fd) __attribute__((__nothrow__, __leaf__));
extern signed int dup2(signed int  __fd, signed int  __fd2) __attribute__((__nothrow__, __leaf__));
extern char  * *__environ;
extern signed int execve(const char  * __path, char  *const  __argv[], char  *const  __envp[]) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern signed int execv(const char  * __path, char  *const  __argv[]) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern signed int execle(const char  * __path, const char  * __arg, ...) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern signed int execl(const char  * __path, const char  * __arg, ...) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern signed int execvp(const char  * __file, char  *const  __argv[]) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern signed int execlp(const char  * __file, const char  * __arg, ...) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern void _exit(signed int  __status) __attribute__((__noreturn__));
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
  _SC_THREAD_ROBUST_PRIO_PROTECT
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
extern signed long pathconf(const char  * __path, signed int  __name) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern signed long fpathconf(signed int  __fd, signed int  __name) __attribute__((__nothrow__, __leaf__));
extern signed long sysconf(signed int  __name) __attribute__((__nothrow__, __leaf__));
extern __pid_t getpid(void) __attribute__((__nothrow__, __leaf__));
extern __pid_t getppid(void) __attribute__((__nothrow__, __leaf__));
extern __pid_t getpgrp(void) __attribute__((__nothrow__, __leaf__));
extern __pid_t __getpgid(__pid_t  __pid) __attribute__((__nothrow__, __leaf__));
extern signed int setpgid(__pid_t  __pid, __pid_t  __pgid) __attribute__((__nothrow__, __leaf__));
extern __pid_t setsid(void) __attribute__((__nothrow__, __leaf__));
extern __uid_t getuid(void) __attribute__((__nothrow__, __leaf__));
extern __uid_t geteuid(void) __attribute__((__nothrow__, __leaf__));
extern __gid_t getgid(void) __attribute__((__nothrow__, __leaf__));
extern __gid_t getegid(void) __attribute__((__nothrow__, __leaf__));
extern signed int getgroups(signed int  __size, __gid_t  __list[]) __attribute__((__nothrow__, __leaf__)) __attribute__((__access__(__write_only__, 2, 1)));
extern signed int setuid(__uid_t  __uid) __attribute__((__nothrow__, __leaf__));
extern signed int setgid(__gid_t  __gid) __attribute__((__nothrow__, __leaf__));
extern __pid_t fork(void) __attribute__((__nothrow__));
extern char  *ttyname(signed int  __fd) __attribute__((__nothrow__, __leaf__));
extern signed int ttyname_r(signed int  __fd, char  * __buf, size_t  __buflen) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2))) __attribute__((__access__(__write_only__, 2, 3)));
extern signed int isatty(signed int  __fd) __attribute__((__nothrow__, __leaf__));
extern signed int link(const char  * __from, const char  * __to) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern signed int unlink(const char  * __name) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern signed int rmdir(const char  * __path) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern __pid_t tcgetpgrp(signed int  __fd) __attribute__((__nothrow__, __leaf__));
extern signed int tcsetpgrp(signed int  __fd, __pid_t  __pgrp_id) __attribute__((__nothrow__, __leaf__));
extern char  *getlogin(void);
extern signed int fsync(signed int  __fd);
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
    (((void)(0)));
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
    (((void)(0)));
    (((void)(0)));
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
    (((void)(0)));
    (((void)(0)));
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
    char  *endpos = ((array_alloc)((a), 1, ((((a))->used))));
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
    (((void)(0)));
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
    (((void)(0)));
    return ((a)->mem);
  }
}
void  array_trunc(array  * a)
{

  ;
  {
    (((void)(0)));
    (((a)->used) = 0);
  }
}
void  array_truncate(array  * a, size_t  membersize, size_t  len)
{

  ;
  {
    size_t newlen;
    (((void)(0)));
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

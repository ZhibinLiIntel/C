#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <errno.h>

static void show_sysconf(char *, int);

int main(void)
{
#ifdef ARG_MAX
	printf("ARG_MAX defined to be %d\n", ARG_MAX+0);
#else
	printf("no symbol for ARG_MAX\n");
#endif
#ifdef _SC_ARG_MAX
	show_sysconf("ARG_MAX", _SC_ARG_MAX);
#else
	printf("no symbol for _SC_ARG_MAX\n");
#endif
#ifdef ATEXIT_MAX
	printf("ATEXIT_MAX defined to be %d\n", ATEXIT_MAX+0);
#else
	printf("no symbol for ATEXIT_MAX\n");
#endif
#ifdef _SC_ATEXIT_MAX
	show_sysconf("ATEXIT_MAX", _SC_ATEXIT_MAX);
#else
	printf("no symbol for _SC_ATEXIT_MAX\n");
#endif
#ifdef CHARCLASS_NAME_MAX
	printf("CHARCLASS_NAME_MAX defined to be %d\n", CHARCLASS_NAME_MAX+0);
#else
	printf("no symbol for CHARCLASS_NAME_MAX\n");
#endif
#ifdef _SC_CHARCLASS_NAME_MAX
	show_sysconf("CHARCLASS_NAME_MAX", _SC_CHARCLASS_NAME_MAX);
#else
	printf("no symbol for _SC_CHARCLASS_NAME_MAX\n");
#endif
#ifdef CHILD_MAX
	printf("CHILD_MAX defined to be %d\n", CHILD_MAX+0);
#else
	printf("no symbol for CHILD_MAX\n");
#endif
#ifdef _SC_CHILD_MAX
	show_sysconf("CHILD_MAX", _SC_CHILD_MAX);
#else
	printf("no symbol for _SC_CHILD_MAX\n");
#endif
#ifdef CLOCKTICKSPERSECOND
	printf("CLOCKTICKSPERSECOND defined to be %d\n", CLOCKTICKSPERSECOND+0);
#else
	printf("no symbol for CLOCKTICKSPERSECOND\n");
#endif
#ifdef _SC_CLK_TCK
	show_sysconf("CLOCKTICKSPERSECOND", _SC_CLK_TCK);
#else
	printf("no symbol for _SC_CLK_TCK\n");
#endif
#ifdef COLL_WEIGHTS_MAX
	printf("COLL_WEIGHTS_MAX defined to be %d\n", COLL_WEIGHTS_MAX+0);
#else
	printf("no symbol for COLL_WEIGHTS_MAX\n");
#endif
#ifdef _SC_COLL_WEIGHTS_MAX
	show_sysconf("COLL_WEIGHTS_MAX", _SC_COLL_WEIGHTS_MAX);
#else
	printf("no symbol for _SC_COLL_WEIGHTS_MAX\n");
#endif
#ifdef DELAYTIMER_MAX
	printf("DELAYTIMER_MAX defined to be %d\n", DELAYTIMER_MAX+0);
#else
	printf("no symbol for DELAYTIMER_MAX\n");
#endif
#ifdef _SC_DELAYTIMER_MAX
	show_sysconf("DELAYTIMER_MAX", _SC_DELAYTIMER_MAX);
#else
	printf("no symbol for _SC_DELAYTIMER_MAX\n");
#endif
#ifdef HOST_NAME_MAX
	printf("HOST_NAME_MAX defined to be %d\n", HOST_NAME_MAX+0);
#else
	printf("no symbol for HOST_NAME_MAX\n");
#endif
#ifdef _SC_HOST_NAME_MAX
	show_sysconf("HOST_NAME_MAX", _SC_HOST_NAME_MAX);
#else
	printf("no symbol for _SC_HOST_NAME_MAX\n");
#endif
#ifdef IOV_MAX
	printf("IOV_MAX defined to be %d\n", IOV_MAX+0);
#else
	printf("no symbol for IOV_MAX\n");
#endif
#ifdef _SC_IOV_MAX
	show_sysconf("IOV_MAX", _SC_IOV_MAX);
#else
	printf("no symbol for _SC_IOV_MAX\n");
#endif
#ifdef LINE_MAX
	printf("LINE_MAX defined to be %d\n", LINE_MAX+0);
#else
	printf("no symbol for LINE_MAX\n");
#endif
#ifdef _SC_LINE_MAX
	show_sysconf("LINE_MAX", _SC_LINE_MAX);
#else
	printf("no symbol for _SC_LINE_MAX\n");
#endif
#ifdef LOGIN_NAME_MAX
	printf("LOGIN_NAME_MAX defined to be %d\n", LOGIN_NAME_MAX+0);
#else
	printf("no symbol for LOGIN_NAME_MAX\n");
#endif
#ifdef _SC_LOGIN_NAME_MAX
	show_sysconf("LOGIN_NAME_MAX", _SC_LOGIN_NAME_MAX);
#else
	printf("no symbol for _SC_LOGIN_NAME_MAX\n");
#endif
#ifdef NGROUPS_MAX
	printf("NGROUPS_MAX defined to be %d\n", NGROUPS_MAX+0);
#else
	printf("no symbol for NGROUPS_MAX\n");
#endif
#ifdef _SC_NGROUPS_MAX
	show_sysconf("NGROUPS_MAX", _SC_NGROUPS_MAX);
#else
	printf("no symbol for _SC_NGROUPS_MAX\n");
#endif
#ifdef OPEN_MAX
	printf("OPEN_MAX defined to be %d\n", OPEN_MAX+0);
#else
	printf("no symbol for OPEN_MAX\n");
#endif
#ifdef _SC_OPEN_MAX
	show_sysconf("OPEN_MAX", _SC_OPEN_MAX);
#else
	printf("no symbol for _SC_OPEN_MAX\n");
#endif
#ifdef PAGESIZE
	printf("PAGESIZE defined to be %d\n", PAGESIZE+0);
#else
	printf("no symbol for PAGESIZE\n");
#endif
#ifdef _SC_PAGESIZE
	show_sysconf("PAGESIZE", _SC_PAGESIZE);
#else
	printf("no symbol for _SC_PAGESIZE\n");
#endif
#ifdef PAGE_SIZE
	printf("PAGE_SIZE defined to be %d\n", PAGE_SIZE+0);
#else
	printf("no symbol for PAGE_SIZE\n");
#endif
#ifdef _SC_PAGE_SIZE
	show_sysconf("PAGE_SIZE", _SC_PAGE_SIZE);
#else
	printf("no symbol for _SC_PAGE_SIZE\n");
#endif
#ifdef RE_DUP_MAX
	printf("RE_DUP_MAX defined to be %d\n", RE_DUP_MAX+0);
#else
	printf("no symbol for RE_DUP_MAX\n");
#endif
#ifdef _SC_RE_DUP_MAX
	show_sysconf("RE_DUP_MAX", _SC_RE_DUP_MAX);
#else
	printf("no symbol for _SC_RE_DUP_MAX\n");
#endif
#ifdef RTSIG_MAX
	printf("RTSIG_MAX defined to be %d\n", RTSIG_MAX+0);
#else
	printf("no symbol for RTSIG_MAX\n");
#endif
#ifdef _SC_RTSIG_MAX
	show_sysconf("RTSIG_MAX", _SC_RTSIG_MAX);
#else
	printf("no symbol for _SC_RTSIG_MAX\n");
#endif
#ifdef SEM_NSEMS_MAX
	printf("SEM_NSEMS_MAX defined to be %d\n", SEM_NSEMS_MAX+0);
#else
	printf("no symbol for SEM_NSEMS_MAX\n");
#endif
#ifdef _SC_SEM_NSEMS_MAX
	show_sysconf("SEM_NSEMS_MAX", _SC_SEM_NSEMS_MAX);
#else
	printf("no symbol for _SC_SEM_NSEMS_MAX\n");
#endif
#ifdef SEM_VALUE_MAX
	printf("SEM_VALUE_MAX defined to be %d\n", SEM_VALUE_MAX+0);
#else
	printf("no symbol for SEM_VALUE_MAX\n");
#endif
#ifdef _SC_SEM_VALUE_MAX
	show_sysconf("SEM_VALUE_MAX", _SC_SEM_VALUE_MAX);
#else
	printf("no symbol for _SC_SEM_VALUE_MAX\n");
#endif
#ifdef SIGQUEUE_MAX
	printf("SIGQUEUE_MAX defined to be %d\n", SIGQUEUE_MAX+0);
#else
	printf("no symbol for SIGQUEUE_MAX\n");
#endif
#ifdef _SC_SIGQUEUE_MAX
	show_sysconf("SIGQUEUE_MAX", _SC_SIGQUEUE_MAX);
#else
	printf("no symbol for _SC_SIGQUEUE_MAX\n");
#endif
#ifdef STREAM_MAX
	printf("STREAM_MAX defined to be %d\n", STREAM_MAX+0);
#else
	printf("no symbol for STREAM_MAX\n");
#endif
#ifdef _SC_STREAM_MAX
	show_sysconf("STREAM_MAX", _SC_STREAM_MAX);
#else
	printf("no symbol for _SC_STREAM_MAX\n");
#endif
#ifdef SYMLOOP_MAX
	printf("SYMLOOP_MAX defined to be %d\n", SYMLOOP_MAX+0);
#else
	printf("no symbol for SYMLOOP_MAX\n");
#endif
#ifdef _SC_SYMLOOP_MAX
	show_sysconf("SYMLOOP_MAX", _SC_SYMLOOP_MAX);
#else
	printf("no symbol for _SC_SYMLOOP_MAX\n");
#endif
#ifdef TIMER_MAX
	printf("TIMER_MAX defined to be %d\n", TIMER_MAX+0);
#else
	printf("no symbol for TIMER_MAX\n");
#endif
#ifdef _SC_TIMER_MAX
	show_sysconf("TIMER_MAX", _SC_TIMER_MAX);
#else
	printf("no symbol for _SC_TIMER_MAX\n");
#endif
#ifdef TTY_NAME_MAX
	printf("TTY_NAME_MAX defined to be %d\n", TTY_NAME_MAX+0);
#else
	printf("no symbol for TTY_NAME_MAX\n");
#endif
#ifdef _SC_TTY_NAME_MAX
	show_sysconf("TTY_NAME_MAX", _SC_TTY_NAME_MAX);
#else
	printf("no symbol for _SC_TTY_NAME_MAX\n");
#endif
#ifdef TZNAME_MAX
	printf("TZNAME_MAX defined to be %d\n", TZNAME_MAX+0);
#else
	printf("no symbol for TZNAME_MAX\n");
#endif
#ifdef _SC_TZNAME_MAX
	show_sysconf("TZNAME_MAX", _SC_TZNAME_MAX);
#else
	printf("no symbol for _SC_TZNAME_MAX\n");
#endif
	exit(0);
}

static void show_sysconf(char *str, int name)
{
	long val;
	errno = 0;
	if(val = sysconf(name) < 0) {
		if(errno == 0) {
			printf("no limit\n");
		}
		else {
			errno = EINVAL;
			printf("not supported\n");
		}
	}
	else {
		printf("%s = %ld\n", str, val);
	}
}

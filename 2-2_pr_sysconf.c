#include <stdio.h>
#include <errno.h>
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>

static void pr_sysconf(char *mesg, int name)
{
	long  val;

        fputs(mesg, stdout);
        errno = 0;
        if((val = sysconf(name)) < 0) {
                if(errno != 0) {
                        if(errno == EINVAL)
                                fputs(" (not supported)\n", stdout);
                        else
                                printf("sysconf error");
                } else {
                        fputs("(no limit)\n", stdout);
                }
        }else {
                printf(" %ld\n", val);
        }
}
int main(int argc, char **argv)
{
#ifdef ARG_MAX
	printf("ARG_MAX defined to be %d\n", ARG_MAX+0);
#else
	printf("no symbol for ARG_MAX\n");
#endif
#ifdef _SC_ARG_MAX
	pr_sysconf("ARG_MAX =", _SC_ARG_MAX);
#else
	printf("no symbol for _SC_ARG_MAX\n");
#endif
#ifdef ATEXIT_MAX
        printf("ATEXIT_MAX defined to be %d\n", ATEXIT_MAX+0);
#else
        printf("no symbol for ATEXIT_MAX\n");
#endif
#ifdef _SC_ATEXIT_MAX
        pr_sysconf("ATEXIT_MAX =", _SC_ATEXIT_MAX);
#else
        printf("no symbol for _SC_ATEXIT_MAX\n");
#endif
}

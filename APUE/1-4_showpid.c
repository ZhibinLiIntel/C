#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
	pid_t pid = getpid();
	printf("This is process %d\n", pid);
	return 0;
}

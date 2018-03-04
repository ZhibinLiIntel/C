#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(void)
{
	char *path = "/home/zhibli/hello";
	if(open(path, O_RDWR) == -1)
		perror(path);
		printf("%s\n", strerror(errno));
	return 0;
}

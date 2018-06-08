#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
	/* Note: Linux's block size is now 4kB(4096 bytes),
	not 512 bytes mentioned in APUE book. */
	char a[] = "ABCDEFGH";
	char b[] = "abcdefgh";
	int fd;
	fd = open("file_with_blank", O_RDWR|O_CREAT|O_EXCL);
	write(fd, a, sizeof(a));
	lseek(fd, 1234, SEEK_SET);
	write(fd, b, sizeof(b));
	close(fd);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
	char a[] = "ABCDEFGH";
	char b[] = "abcdefgh";
	int fd;
	fd = open("file_with_blank", O_RDWR|O_CREAT|O_EXCL);
	write(fd, a, strlen(a));
	lseek(fd, 1234, SEEK_SET);
	write(fd, b, strlen(b));
	close(fd);
	return 0;
}

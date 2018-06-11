#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
	int fd1 = open("file_with_blank", O_RDWR);
	int fd2 = open("file_without_blank", O_WRONLY|O_CREAT|O_TRUNC, 0644);
	char buf;
	while (read(fd1, &buf, 1) > 0) {
		if (buf != '\0')
			write(fd2, &buf, 1);
	}
	return 0;
}

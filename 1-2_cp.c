#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
	int n;
	char buf[10];
	int fd1 = open(argv[1], O_RDONLY);
	int fd2 = open(argv[2], O_RDWR);
	//10 is the buffer size defined
	//注意while(n = read(fd1, buf, 10) > 0)是错的，这样会先比较是否大于0，true则返回1，这时赋给n的值为1
	while((n = read(fd1, buf, 10)) > 0){
		if(write(fd2, buf, n) != n){
			printf("error\n");
			exit(1);
		}
	}
	exit(0);
}

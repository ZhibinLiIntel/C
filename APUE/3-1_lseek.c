#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
	off_t offset;
	int fd, fdir;
	fdir = open("/home/haoyouab/", O_RDONLY);
	//openat可以指定其他目录为工作目录（working dir）而不是像open一样只能默认当前目录为工作目录，本例子中指定了/home/haoyouab
	fd = openat(fdir, argv[1],  O_RDONLY);
	//fd = open(argv[1], O_RDONLY);
	if((offset = lseek(fd, 0, SEEK_CUR)) == -1){
		printf("cannot seek\n");
	}
	else{
		printf("seek OK\n");
	}
	exit(0);
}

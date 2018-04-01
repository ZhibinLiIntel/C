#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char **argv)
{
	struct stat buf;
	int i;
	for (i = 1; i < argc; i++) {
		lstat(argv[i], &buf);
		if (S_ISREG(buf.st_mode))
			printf("regular file\n");
		else if (S_ISDIR(buf.st_mode))
			printf("directory\n");
		else if (S_ISBLK(buf.st_mode))
			printf("block\n");
		else if (S_ISCHR(buf.st_mode))
			printf("character\n");
	}
	return 0;
}

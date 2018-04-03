#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char **argv)
{
	if (argc != 2) {
		printf("Usage: a.out <file>\n");
		exit(1);
	}
	if (access(argv[1], F_OK) == 0) {
		if (access(argv[1], R_OK) == 0)
			printf("Read \033[1;32m[OK]\n\033[0m");
		else {
			printf("Read \033[1;31m[FAILED]\033[0m");
			printf(" - %s\n", strerror(errno));
		}
		if (open(argv[1], O_RDONLY) > 0)
			printf("Open \033[1;32m[OK]\n\033[0m");
		else {
			printf("Open \033[1;31m[FAILED]\033[0m");
			printf(" - %s\n", strerror(errno));
		}
	}
	else
		printf("File does not exist\n");
}

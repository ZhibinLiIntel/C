#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	if (argc != 2) {
		printf("Usage: a.out <file>\n");
		exit(1);
	}
	if (access(argv[1], F_OK) == 0)
		printf("file exists\n");
	else
		printf("file does not exist\n");
	return 0;
}

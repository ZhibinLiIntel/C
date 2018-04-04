#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
	umask(0);
	if (creat("foo", 0660) < 0) {
		printf("Can't create file\n");
		exit(1);
	}
	umask(0033);
	creat("foo2", 0777);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

void set_fl(int, int);

void set_fl(int fd, int flags)
{
	int val;
	val = fcntl(fd, F_GETFL, 0);
	val |= flags;
	fcntl(fd, F_SETFL, val);
}

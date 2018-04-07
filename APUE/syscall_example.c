#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <syscall.h>
#include <fcntl.h>

int main(void)
{
	struct { int type, pid; } owner = { F_OWNER_TID, 1234567890 };
	syscall(__NR_fcntl, 0, F_SETOWN_EX, &owner);
	syscall(__NR_open, "open.sample", O_RDONLY|O_CREAT, 0400);
	syscall(__NR_unlink, "open.sample");
	return 0;
}

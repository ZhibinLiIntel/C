#include <stdio.h>
#include <stdlib.h>

static int
count_one(int num)
{
	int count = 0;
	while (num) {
		num &= num - 1;
		count++;
	}
	return count;
}

int
main(void)
{
	int num = count_one(-1);
	printf("%d\n", num);
	return 0;
}

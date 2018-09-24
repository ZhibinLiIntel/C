#include <stdio.h>
#include <stdlib.h>

static int
fibonacci(int n)
{
	if (n <= 1)
		return n;
	int first = 0;
	int second = 1;
	int next = 0;
	for (int i = 2; i <= n; i++) {
		next = first + second;
		first = second;
		second = next;
	}
	return next;
}

int
main(void)
{
	int num = fibonacci(4);
	printf("%d\n", num);
}

#include <stdio.h>
#include <stdlib.h>

extern int increment(int);
extern int negate(int);

#define NUM 3
int main(void)
{
	int a[NUM] = { 10, 0, -10 };
	int retval_increment, retval_negate;
	for (int i = 0; i < NUM; i++) {
		retval_increment = increment(a[i]);
		retval_negate = negate(a[i]);
		printf("return value of increment = %d\treturn value of negate = %d\n", retval_increment, retval_negate);
	}
	return EXIT_SUCCESS;
}

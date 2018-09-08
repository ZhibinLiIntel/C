#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static bool
find(int **array, int a, int b, int target)
{
	int i, j, point;
	for (i = 0, j = b - 1; i < a && j >= 0;) {
		point = *((int *) array + b * i + j);
		if (point > target) {
			j--;
		} else if (point < target) {
			i++;
		} else
			return true;
	}
	return false;
}

int
main(void)
{
	int array[5][4] = { { 1, 2, 8, 9 }, { 2, 4, 9, 12 }, { 4, 7, 10, 13 }, { 6, 8, 11, 15 }, {7, 9, 12, 16 } };
	bool test = find((int **)array, 5, 4, 7);
	if (test)
		printf("true\n");
	else
		printf("false\n");
}

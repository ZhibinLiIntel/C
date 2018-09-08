#include <stdio.h>
#include <stdlib.h>

#define LEN 7

static void
quick_sort(int a[], int low, int high)
{
	if (low > high)
		return;
	int pivot = a[low];
	int forward = low;
	int backward = high;
	while (forward < backward) {
		while (a[backward] >= pivot && backward > forward) {
			backward--;
		}
		a[forward] = a[backward];
		while (a[forward] <= pivot && forward < backward) {
			forward++;
		}
		a[backward] = a[forward];
	}
	a[forward] = pivot;
	quick_sort(a, low, forward - 1);
	quick_sort(a, backward + 1, high);
}

int
main(void)
{
	int a[LEN] = { 12, 34, 8, 9 ,2, 33, 58 };
	quick_sort(a, 0, 6);
	for (int i = 0; i < LEN; i++) {
		printf("a[%d] = %d\n", i, a[i]);
	}

	return 0;
}

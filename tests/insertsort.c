#include <stdio.h>

void insertsort(int *a, int len)
{
	int i, j;
	for (i = 0; i < len - 1; i++) {
		int tmp = a[i + 1];
		for (j = i; a[j] > tmp && j >= 0; j--) {
			a[j + 1] = a[j];
		}
		a[j + 1] = tmp;
	}
}

void binary_insertsort(int *a, int len)
{
	for (int i = 1; i < len; i++) {
		int left = 0;
		int right = i - 1;
		int tmp = a[i];
		while (left <= right) {
			int mid = (left + right) / 2;
			if (a[mid] > tmp)
				right = mid - 1;
			else
				left = mid + 1;
		}
		for (int j = i - 1; j >= left; j--) {
			a[j + 1] = a[j];
		}
		a[left] = tmp;
		for (int h = 0; h < len; h++)
			printf("%d ", a[h]);
		printf("\n");
	}
}

int
main(void)
{
	int a[] = { 3, 7, 5, 1, 6, 0, -1 };
	//insertsort(a, sizeof(a) / sizeof(int));
	binary_insertsort(a, 7);
	for (int i = 0; i < 7; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}

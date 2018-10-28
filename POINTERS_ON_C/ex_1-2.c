#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int ch;
	int row = 1;
	int begin = 1;
	while ((ch = getchar()) != EOF) {
		if (begin == 1) {
			begin = 0;
			printf("%d ", row);
			row++;
		}

		if (ch == '\n') {
			begin = 1;
		}
		putchar(ch);
	}
	return 0;
}

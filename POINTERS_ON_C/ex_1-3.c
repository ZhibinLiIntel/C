#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int ch;
	signed char checksum = -1;
	while ((ch = getchar()) != EOF) {
		putchar(ch);
		checksum += ch;
	}
	printf("%d\n", checksum);
	return EXIT_SUCCESS;
}

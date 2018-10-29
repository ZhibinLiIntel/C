#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1001

int main(void)
{
	int max = -1;
	int len;
	char str[MAX_LEN];
	char output[MAX_LEN];
	while (fgets(str, MAX_LEN, stdin) != NULL) {
		len = strlen(str);
		if (len > max) {
			max = len;
			strcpy(output, str);
		}
	}

	if (max >= 0)
		puts(output);

	return EXIT_SUCCESS;
}

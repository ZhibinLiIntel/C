#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 1000

bool is_paired(void)
{
	int top = 0;
	int ch;
	while ((ch = getchar()) != EOF) {
		if (ch == '{') {
			top++;
		}
		if (ch == '}') {
			if (top > 0)
				--top;
			else
				return false;
		} 
	}
	if (top != 0)
		return false;
	else
		return true;
}

int main(void)
{
	bool result = is_paired();
	if (result)
		printf("SUCCEED\n");
	else
		printf("FAILED\n");
	return EXIT_SUCCESS;
}

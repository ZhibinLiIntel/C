#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char *
replace_space(char str[], int len)
{
	int space_count = 0;
	int oldlen = strlen(str);
	for (int i = 0; i < oldlen; i++) {
		if (str[i] == ' ')
			space_count++;
	}
	int newlen = oldlen + space_count * 2;
	if (newlen > len)
		return NULL;
	for (int j = oldlen, i = newlen; j >= 0; ) {
		if (str[j] == ' ') {
			j--;
			str[i--] = '0';
			str[i--] = '2';
			str[i--] = '%';
		} else {
			str[i--] = str[j--];
		}
	}
	return str;
}

int
main(void)
{
	char a[30] = "We are happy";
	char *str = replace_space(a, 30);
	if (str)
		printf("%s\n", str);
	return 0;
}

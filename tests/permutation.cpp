#include <iostream>
using namespace std;
#include <assert.h>

void permutation(char *pstr, char *pbegin)
{
	assert(pstr && pbegin);
	if (*pbegin == '\0')
		printf("%s\n", pstr);
	else {
		for (char *p = pbegin; *p != '\0'; p++) {
			swap(*pbegin, *p);
			permutation(pstr, pbegin + 1);
			swap(*pbegin, *p);
		}
	}
}

int main(void)
{
	char str[] = "abc";
	permutation(str, str);
	return 0;
}

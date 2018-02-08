#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	int n;
	char buf[BUFFSIZE];
	while(n = read(STDIN_FILENO, buf, BUFFSIZE) > 0){
		if(write(STDOUT_FILENO, buf, n) != n){
			printf("error\n");
			exit(1);
		}
	exit(0);
}

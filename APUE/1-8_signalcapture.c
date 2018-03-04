#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>
#define MAX 255

static void sig_int(int);

int main(void)
{
	char buf[MAX];
	pid_t pid;	
	int status;
	if(signal(SIGINT, (__sighandler_t)sig_int) == SIG_ERR){
		printf("error!\n");
		exit(1);
	}
	printf("%% ");
	while(fgets(buf, MAX, stdin) != NULL){
		buf[strlen(buf) - 1] = 0;
		pid = fork();
		if(pid < 0){
			printf("fork error\n");
			exit(1);
		}
		else if(pid == 0){
			execlp(buf, buf, (char *)0);
		}
			waitpid(pid, &status, 0);
		printf("%% ");
	}
	return 0;
}

void sig_int(int signo)
{
	//unresolved issue here
	printf("interrupt\n%% ");
}

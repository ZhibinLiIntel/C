#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#define MAX 255

int main(int argc, char **argv)
{
	char buf[MAX];
	pid_t pid;
	int status;
	printf("%% ");	
	//这里使用标准I/O函数，注意fgets和read的区别
	while(fgets(buf, MAX, stdin) != NULL){
		buf[strlen(buf) - 1] = 0;
		//从标准输入读取命令后需要用fork创建子进程来执行命令，父进程负责接收命令输入，因为exec系列函数不会返回，若由父进程调用则无法在执行完之后进程退出，无法接收下一个命令输入
		pid = fork();
		if(pid < 0){
			printf("fork error");
			exit(1);
		}
		else if(pid == 0){	
			execlp(buf, buf, (char *)0);	
		}
		else{
			waitpid(pid, &status, 0);
			printf("%% ");
		}
	}
	return 0;
}

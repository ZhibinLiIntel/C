#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define MAX 256
typedef struct msg { //用来向其他客户端发送信息的结构体
	char name[MAX]; //消息来源
	char text[1024]; //消息内容
} MSG;

typedef struct request { //向服务器发起请求的结构体
	char type; //R代表register即请求注册，C代表connect即连接请求
	char id[MAX]; //客户端id
} REQUEST;

typedef struct response{ //从服务器接收响应的结构体
	char id[MAX]; //客户端id
	char ip[MAX]; //客户端ip
	char port[MAX]; //客户端端口
} RESPONSE;

RESPONSE reg(int sockfd, struct sockaddr_in serveraddr) //注册函数
{
	REQUEST cli_req;
	RESPONSE cli_res;
	socklen_t sockaddr_len = sizeof(struct sockaddr);

        printf("请设置本客户端ID： ");
        scanf("%s", &cli_req.id);
	cli_req.type = 'R';
		
	sendto(sockfd, &cli_req, sizeof(cli_req), 0, (struct sockaddr *) &serveraddr, sizeof(serveraddr));//向服务器发送注册请求
	if(recvfrom(sockfd, &cli_res, sizeof(cli_res), 0, (struct sockaddr *) &serveraddr, &sockaddr_len) < 0)
		exit(1);
	//printf("%s\n", cli_res.ip);
	return cli_res;	
}

RESPONSE conn(int sockfd, struct sockaddr_in serveraddr) //连接指定客户端函数
{
	REQUEST obj_req;
	RESPONSE obj_res;
	socklen_t sockaddr_len = sizeof(struct sockaddr);

	printf("请输入要连接的客户端ID： ");
        scanf("%s", &obj_req.id);
	obj_req.type = 'C'; 

	sendto(sockfd, &obj_req, sizeof(obj_req), 0, (struct sockaddr *) &serveraddr, sizeof(serveraddr)); //向服务器发送连接其他客户端的请求
	recvfrom(sockfd, &obj_res, sizeof(obj_res), 0, (struct sockaddr *) &serveraddr, &sockaddr_len); //接收服务器的响应信息
	//printf("%s\n", obj_res.port);
	return obj_res;	
}

void chat(int sockfd, RESPONSE obj_res)
{
	struct sockaddr_in objaddr; //objaddr是想要连接的客户端
	char mesg[MAX];
	pid_t pid;
	socklen_t sockaddr_len = sizeof(struct sockaddr);
	
	memset(&objaddr, 0, sizeof(objaddr));
	objaddr.sin_family = AF_INET;
	objaddr.sin_addr.s_addr = inet_addr(obj_res.ip);
	int test = atoi(obj_res.port);
	objaddr.sin_port = htons(test);

	while(1){
		pid = fork();
		if(pid > 0) {
			scanf("%s", mesg);
			sendto(sockfd, mesg, sizeof(mesg), 0, (struct sockaddr *) &objaddr, sizeof(objaddr));
		}
		else {
			recvfrom(sockfd, mesg, sizeof(mesg), 0, (struct sockaddr *) &objaddr, &sockaddr_len);
			printf("%s: %s\n", obj_res.id, mesg);
		}
		waitpid(&pid, 0, 0);	
	}		
}

int main(int argc, char **argv)
{
	int sockfd, sockfd2;
	struct sockaddr_in serveraddr, selfaddr;
	char saddr[256], cli_id[256], obj_id[256]; //saddr：服务器地址，cli_id：本机ID，obj_id：通信对象ID
	RESPONSE self, obj;
	socklen_t sockaddr_len = sizeof(struct sockaddr);

        printf("请输入服务器地址： "); //用于支持局域网内登陆，所以不采用本机地址127.0.0.1
        scanf("%s", &saddr);

	if((sockfd = socket(PF_INET, SOCK_DGRAM, 0)) < 0) {
                exit(1);
        }

	memset(&serveraddr, 0, sizeof(serveraddr));
        serveraddr.sin_family = AF_INET;
        serveraddr.sin_addr.s_addr = inet_addr(saddr);
        serveraddr.sin_port = htons(8888); //统一设置服务器端口为8888

	self = reg(sockfd, serveraddr);
	close(sockfd);
	memset(&selfaddr, 0, sizeof(selfaddr));
	selfaddr.sin_family = AF_INET;
	selfaddr.sin_addr.s_addr = inet_addr(self.ip);
	int test = atoi(self.port);
	//printf("%d\n", test);
	selfaddr.sin_port = htons(test);
	//printf("%s\n", self.ip);
	//printf("%s\n", self.port);
	//printf("%s\n", inet_ntoa(selfaddr.sin_addr));
	//printf("%d\n", ntohs(selfaddr.sin_port));
	if((sockfd = socket(PF_INET, SOCK_DGRAM, 0)) < 0) {
                exit(1);
        }
	if(bind(sockfd, (struct sockaddr *) &selfaddr, sizeof(selfaddr)) < 0) {
		exit(1);
	}
	
	
	obj = conn(sockfd, serveraddr);
	printf("%s\n", obj.ip);
	printf("%s\n", obj.port);
	chat(sockfd, obj);
	return 0;
}

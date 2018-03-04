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

typedef struct request { //向服务器发起请求的结构体
	char type; //R代表register即请求注册，C代表connect即连接请求
	char id[MAX]; //客户端id
} REQUEST;

typedef struct response{ //响应客户端请求的结构体
	char id[MAX]; //客户端id
	char ip[MAX]; //客户端ip
	char port[MAX]; //客户端端口
} RESPONSE;

typedef struct node {
	RESPONSE res;
	struct node *next;	
} listnode, *linklist;

linklist linklist_create() {
	linklist head;
	if ((head = (linklist) malloc(sizeof(listnode))) == NULL) {
		exit(1);
	}
	head -> next = NULL;
	return head;
}

int main(int argc, char **argv)
{
	int sockfd;
	char str[200];
	struct sockaddr_in serveraddr, clientaddr;
	socklen_t sockaddr_len = sizeof(struct sockaddr);
	REQUEST req;
	RESPONSE res, res2;
	
	linklist head = linklist_create();//创建链表
	
	if((sockfd = socket(PF_INET, SOCK_DGRAM, 0)) < 0) {
		exit(1);	
	}
	
	memset(&serveraddr, 0, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	serveraddr.sin_port = htons(8888);
	if(bind(sockfd, (struct sockaddr*) &serveraddr, sizeof(serveraddr)) < 0) {
		exit(1);	
	}
	memset(&clientaddr, 0, sizeof(clientaddr));
	while(1) {
		recvfrom(sockfd, &req, sizeof(req), 0, (struct sockaddr *) &clientaddr, &sockaddr_len);
		//printf("%c\n", req.type);
		//printf("%s\n", inet_ntoa(clientaddr.sin_addr));
		//printf("%d\n", ntohs(clientaddr.sin_port));
		if(req.type == 'R') { //R表示register，即向服务器注册客户端的信息
			linklist node;
			node = (linklist)malloc(sizeof(listnode));
			strcpy(node -> res.id, req.id);
			strcpy(node -> res.ip, inet_ntoa(clientaddr.sin_addr));
			sprintf(str,"%d", ntohs(clientaddr.sin_port));//画重点
			strcpy(node -> res.port, str);
			node -> next = head -> next;
			head -> next = node;
			strcpy(res2.id, node -> res.id);
			strcpy(res2.ip, node -> res.ip);
			strcpy(res2.port, node -> res.port);
			if(sendto(sockfd, &res2, sizeof(res2), 0, (struct sockaddr *) &clientaddr, sizeof(clientaddr)) < 0)
						fprintf(stderr, "%s\n", strerror(errno));
		}
		else if(req.type == 'C') { //C表示connect，即请求连接其他客户端的信息
			
			linklist node = head -> next;
			while(node != NULL) {
				if(strcmp(req.id, node -> res.id) == 0) {
					strcpy(res.id, node -> res.id);
					strcpy(res.ip, node -> res.ip);
					strcpy(res.port, node -> res.port);
					if(sendto(sockfd, &res, sizeof(res), 0, (struct sockaddr *) &clientaddr, sizeof(clientaddr)) < 0)
						fprintf(stderr, "%s\n", strerror(errno));
				}
				node = node -> next;
			}
			
		}
		printf("%s\n", head -> next -> res.ip);
		printf("%s\n", head -> next -> res.port);
		
	}
	return 0;
}

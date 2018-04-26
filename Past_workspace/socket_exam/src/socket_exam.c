/*
 ============================================================================
 Name        : socket_exam.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>

int main(int argc, char *argv[]) {
	int listenfd = 0, connfd =0;
	struct sockaddr_in serv_addr;

	char sendBuff[1024];
	time_t ticks;

	listenfd = socket(AF_INET, SOCK_STREAM,0);
	memset(&serv_addr, '0',sizeof(serv_addr));
	memset(sendBuff, '0',sizeof(sendBuff));

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(5000);

	bind(listenfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

	listen(listenfd, 10);

	while(1){// 현재 시간을 클라이언트에 보내줌. 포트번호는 5000인듯
		connfd = accept(listenfd, (struct sockaddr*)NULL, NULL);

		ticks = time(NULL);
//		snprintf(sendBuff, sizeof(sendBuff),"%.24s\r\n",ctime(&ticks));
		snprintf(sendBuff,sizeof(sendBuff),"go to hell\n");
		write(connfd, sendBuff, strlen(sendBuff));

		close(connfd);
		sleep(1);
	}
	return EXIT_SUCCESS;
}

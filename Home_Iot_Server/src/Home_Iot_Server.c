/*
 ============================================================================
 Name        : Home_Iot_Server.c
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

int main(void) {
 int listenfd = 0, connfd = 0;
 struct sockaddr_in serv_addr;

 char recvBuff[1024];
 char sendBuff[1024];

 listenfd = socket(AF_INET, SOCK_STREAM, 0);
 memset(&serv_addr, '0', sizeof(serv_addr)); // setting value set default to '0'

 serv_addr.sin_family = AF_INET;
 serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
 serv_addr.sin_port = htons(5000);

 bind(listenfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr));

 listen(listenfd, 10);

 printf("start server!!\n");

 while (1) {

  int n = 0;

  memset(recvBuff, 0, sizeof(recvBuff));
  memset(sendBuff, 0, sizeof(sendBuff));

  connfd = accept(listenfd, (struct sockaddr*) NULL, NULL); //서버에서 응답을 기다림(client에 연결되기전 까지)
  n = read(connfd, recvBuff, 1024); //연결되는 순간 read에 걸림, 그리고 input 하는 순간 recvBuff 에 저장
  recvBuff[n] = 0; //
  printf("recvBuff : %s\n", recvBuff);
  strcpy(sendBuff, recvBuff);
  write(connfd, sendBuff, strlen(sendBuff));

  close(connfd); // 이게 없으면 계속 data를 주고 받음
  sleep(1);

 }

 return 0;
}




/*
 ============================================================================
 Name        : Home_Iot_Server_ver02.c
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
#include <ctype.h>

#define BUF_SIZE 1024
#define TV "TV"
#define AIRCON "AIRCON"
#define LAMP "LAMP"
#define DOOR "DOOR"

void toupperstr(char* text) {
 for(int i = 0; i < strlen(text); i++) {
  text[i] = toupper(text[i]);
 }
}

void print_menu_list() {
 printf("==========================\n");
 printf("- HOME IOT CONTROLLER -\n");
 printf("==========================\n");
 printf("0.LIST MENU\n");
 printf("1.TV - ON/OFF\n");
 printf("2.AIRCON - ON/OFF\n");
 printf("3.LAMP - ON/OFF\n");
 printf("4.DOOR - ON/OFF\n");
 printf("10.EXIT\n");
}

int main(void) {
 int listenfd = 0, connfd = 0;
 struct sockaddr_in serv_addr;

 char recvBuff[BUF_SIZE];
 char sendBuff[BUF_SIZE];

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

  connfd = accept(listenfd, (struct sockaddr*) NULL, NULL);
  n = read(connfd, recvBuff, BUF_SIZE);
  recvBuff[n] = 0;
  printf("recvBuff : %s\n", recvBuff);

    toupperstr(recvBuff);
    if(strncmp(recvBuff, TV, strlen(TV)) == 0) {
     printf("Number is 1.\n");
    } else if(strncmp(recvBuff, AIRCON, strlen(AIRCON)) == 0) {
     printf("Number is 2.\n");
    } else {
     printf("Number is not.\n");
    }

  write(connfd, sendBuff, strlen(sendBuff));

  close(connfd);
  sleep(1);

 }

 return 0;
}

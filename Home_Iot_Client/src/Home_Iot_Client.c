/*
 ============================================================================
 Name        : Home_Iot_Client.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) { // argc 배열의 갯수, argv 배열의 값들을 배열에 넣음
 int sockfd = 0, n = 0;
 char sendBuff[BUF_SIZE];
 char recvBuff[BUF_SIZE];
 struct sockaddr_in serv_addr;
 char * ip = NULL;
 char * port = NULL;

 if (argc != 3) { // argc 가 3개가 안된다라면,
  printf("\n Usage: %s <ip> <port>\n", argv[0]); // 무조건 이 메세지 출력
  return 1; // 운영체제에게 오류가 생겼다는 것을 말하는것 (1이든 무슨값이든 상관없음).
 }

 memset(recvBuff, 0, sizeof(recvBuff)); // 0으로 값을 초기(이유는 밑에 참고)

 if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) { // sock_stream은 관례적으로 적어줌 (IPv4 인지 IPv6인지 알려주면됨)
  printf("\n Error : Could not create socket \n");
  return 1;
 }

 ip = argv[1]; // argv 1 이 ip
 port = argv[2]; // argv 2가 port

 memset(&serv_addr, '0', sizeof(serv_addr)); // 구조체에 어떤 값들이 있을건데,  많이 있을 경우 일일히 0으로 초기화 하기 귀찮아서 한꺼번에 0으로 초기

 serv_addr.sin_family = AF_INET; // ipv4를 한다는 의미 (써주기만 하면됨)
 serv_addr.sin_port = htons(atoi(port)); // htons 빅엔디안, 리틀엔디안을 방지해주는 역할 (써주기만 하면 알아서 처리해줌)

 /*
 char test[10] = {'1','0','0',0}; // 뒤에 0이 있어서 string 형
 test = "100";

 int num = 100; 이렇게 쓰고 싶을때
 int num = atoi(test); 라고 하면 바로 숫자 100으로 바껴짐
 */



 if (inet_pton(AF_INET, ip, &serv_addr.sin_addr) <= 0) {
  printf("\n inet_pton error occured\n");
  return 1;
 }

 if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr))
   < 0) { // ip 값을 찾아서 처리해
  printf("\n Error : Connect Failed \n");
  return 1;
 }

 printf("input : ");
 scanf("%s", sendBuff);

 write(sockfd, sendBuff, strlen(sendBuff)); // scanf 값을 write 하면 서버에 내용이 보내짐
    while ( (n = read(sockfd, recvBuff, sizeof(recvBuff)-1)) > 0) // 내용을 read
    {
        recvBuff[n] = 0;
        if(fputs(recvBuff, stdout) == EOF) // printf == fputs 와 같다
        {
            printf("\n Error : Fputs error\n");
        }
    }

    printf("\n"); // recvBuff 값을 출력
    //telnet 원래 콘솔 원격 접속 기능

 return 0;
}

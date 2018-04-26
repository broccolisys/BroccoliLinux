/*
 ============================================================================
 Name        : str2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 1024

int main(void) {
	char title[BUF_SIZE];

	char hello1[BUF_SIZE];	//stack
	char* hello2= (char*)malloc(sizeof(char*)*BUF_SIZE);	//heap

	memset(hello1, 0 , BUF_SIZE);
	memset(hello2, 0 , BUF_SIZE);

	strcpy(hello1, "hello1");	//배열에 넣는건 {"h","e",...} 이런식으로~
	strcpy(hello2, "hello2");

	printf("%s\n", hello1);
	printf("%s\n", hello2);

	strcat(hello1," world");
	strcat(hello2," world");

	printf("%s\n", hello1);
	printf("%s\n", hello2);

	sprintf(title,"<title>%s</title>",hello1);

	printf("%s\n",title);
	printf("<title>%s</title>\n",hello2);

	free(hello2);
	hello2=NULL;	// 이 밑에도 많은 소스코드가 있을 때 유용. 체크용
	//만약 실수로 free하기 전 malloc을 또 해버리면 이전 데이터는 (더 이상 접근할 수 없는)더미데이터가 된다.

	return EXIT_SUCCESS;
}

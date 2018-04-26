/*
 ============================================================================
 Name        : str1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void reverse_text(char* msg){
	int i,j;
	char temp;
	int length=0;
	length=(int)strlen(msg);
	j=length-1;

	for(i=0;i<length/2;i++){
		temp=msg[i];
		msg[i]=msg[j];
		msg[j]=temp;
		j--;
	}
	printf("%s\n",msg);
}

int main(void) {
	char hello1[6]={104,101,108,108,111,0};	//stack 0이 없으면 char 배열로 인식
	char hello2[6]={'h','e','l','l','o',0};	// 0이 없으면 strcpy 같은 함수를 못쓰게 됨!
	char hello3[1024]="hello world!!!!";
	char* hello4	="hello";		// text(const) hello가 저장된 메모리 주소를 할당함
	char* hello5	=(char*)malloc(sizeof(char)*6);		// heap

	printf("%c %c\n",toupper("a"), tolower("B"));

	memset(hello5, 0, sizeof(char) *6);
	strcpy(hello5,"hello");

	printf("이클립스 오류 아님 \n");
	reverse_text(hello1);
	reverse_text(hello2);
	reverse_text(hello3);
	reverse_text(hello5);	//4가 안되는 이유는 프로그램 상수값을 컴파일하면 상수데이터에 들어감
	//상수데이터에는 값을 바꿀 수 없으니까.

	printf("hello1 : %s (len : %lu)\n",hello1, strlen(hello1));
	printf("hello2 : %s (len : %lu)\n",hello2, strlen(hello2));
	printf("hello3 : %s (len : %lu)\n",hello3, strlen(hello3));
	printf("hello5 : %s (len : %lu)\n",hello5, strlen(hello5));

	free(hello5);
	return EXIT_SUCCESS;
}

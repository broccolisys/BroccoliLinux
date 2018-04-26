/*
 ============================================================================
 Name        : Project01.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	char hello1[6]={104,101,108,108,111,0};	//stack
	char hello2[6]={'h','e','l','l','o',0};	//stack
	char hello3[6]="hello";
	char* hello4	="hello";		// text(const)
	char* hello5	=(char*)malloc(sizeof(char)*6);

	memset(hello5,0,sizeof(char)*6);
	strcpy(hello5, "hello");

	printf("hello1 : %s (len : %lu\n",hello1, strlen(hello1));
	printf("hello2 : %s (len : %lu\n",hello2, strlen(hello2));
	printf("hello3 : %s (len : %lu\n",hello3, strlen(hello3));
	printf("hello4 : %s (len : %lu\n",hello4, strlen(hello4));
	printf("hello5 : %s (len : %lu\n",hello5, strlen(hello5));
	return EXIT_SUCCESS;
}

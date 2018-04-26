/*
 ============================================================================
 Name        : upperlower.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define BUF_SIZE 1024

void toupperstr(char* text);
void tolowerstr(char* text);

int main(void) {
	//char a= 'a';
	//char b= 'B';
	char text[BUF_SIZE] = {0,};

	//printf("upper : %c\n",toupper('a'));
	//printf("lower : %c\n",tolower('B'));


	strcpy(text,"Hello World!!");

	printf("%s\n", text);

	toupperstr(text);

	printf("%s\n", text);

	tolowerstr(text);

	printf("%s\n", text);


	return EXIT_SUCCESS;
}

void toupperstr(char* text){
	int length=(int)strlen(text);
	int i;

	for(i=0;i<length;i++){
		text[i]=toupper(text[i]);
	}
}

void tolowerstr(char* text){
	int length=(int)strlen(text);
		int i;

		for(i=0;i<length;i++){
			text[i]=tolower(text[i]);
		}
}

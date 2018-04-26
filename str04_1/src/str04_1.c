/*
 ============================================================================
 Name        : str04_1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void toupperstr(char* text);
void tolowerstr(char* text);
#define BUF_SIZE 1024

int main(void) {
	char text[BUF_SIZE] = {0, };

	strcpy(text, "Hello World!!");
	printf("%s\n", text);
	toupperstr(text);

	printf("%s\n", text);
	tolowerstr(text);

	printf("%s\n",text);

	return EXIT_SUCCESS;
}

void toupperstr(char* text){
	for (int i=0; i <= strlen(text); i++){
		text[i] = toupper(text[i]);
	}
}

void tolowerstr(char* text){
	for (int i=0; i <= strlen(text); i++){
		text[i] = tolower(text[i]);
	}
}

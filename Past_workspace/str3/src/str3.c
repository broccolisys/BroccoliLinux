/*
 ============================================================================
 Name        : str3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
// strcat , sprintf 사용 예
// 소켓 통신을 위한 몸풀기
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 1024

void serialize_element_with_sprintf(char* element,char* url, char* url_name);
void serialize_element_with_strcat(char* element,char* url, char* url_name);

int main(void) {
	char* url = "http://www.naver.com";
	char* url_name = "NAVER";

	char element1[BUF_SIZE];
	char* element2 = (char*) malloc(sizeof(char) *BUF_SIZE);

	memset(element1,0,BUF_SIZE);
	memset(element2,0,BUF_SIZE);

	serialize_element_with_sprintf(element1, url, url_name);
	serialize_element_with_strcat(element2, url, url_name);

	printf("%s\n", element1);
	printf("%s\n", element2);

	free(element2);
	element2 = NULL;

	return EXIT_SUCCESS;
}

void serialize_element_with_sprintf(char* element, char* url, char* url_name){
	sprintf(element,"<a href='%s/'>%s</a>",url,url_name);
}

void serialize_element_with_strcat(char* element, char*url, char* url_name){
	strcat(element,"<a href='");
	strcat(element,url);
	strcat(element,"/'>");
	strcat(element,url_name);
	strcat(element,"</a>");
}

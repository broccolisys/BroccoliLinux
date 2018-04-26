/*
 ============================================================================
 Name        : struct.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define MEMBER 2
#define ZERO 0

typedef struct{
	//char name[10];
	char phone[20];
	char name[10];
	//char* phone = (char*)malloc(sizeof(char)*20);
	int age;
}info_t;

int main(void) {
	//info_t* info[MEMBER];
	info_t info[MEMBER];
	int i, j;

	for(i=ZERO;i<MEMBER;i++){
		printf("name : ");
		scanf("%s",info[i].name);

		printf("age : ");
		scanf("%d",&info[i].age);

		puts("----------------------------------------");
		for(j=ZERO;j<i+1;j++){
			printf("|\t name : %10s\t|\t age : %3d\t|\n", info[j].name, info[j].age);
		}
		puts("----------------------------------------");
	}

	//free(info);
	//info = NULL;
	return EXIT_SUCCESS;
}

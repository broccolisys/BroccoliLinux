/*
 ============================================================================
 Name        : Home_IOT_ver2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "./Interface/Interface.h"
#include "./Utils/Types.h"
#include "./Utils/exLower.h"
#define CHECK "NUMBER is "
#define BUF_SIZE 1024

int main(void) {

	char text[BUF_SIZE] = {0, };
	do {
		interface();
		printf("Input Name : ");
		scanf("%s", &text);
		tolowerstr(text);
		if (strcmp(text,"tv")==0){ // !strcmp(text,"tv")
			printf(CHECK);
			printf(TV);
		}
		else if (!strcmp(text,"aircon")){
			//0의 값을 반환하기 때문에 if 에서 false로 인식, 그래서 !를 붙여주어 1로 변환 true
			printf(CHECK);
			printf(AIRCON);
		}
		else if (!strcmp(text,"lamp")){
			printf(CHECK);
			printf(LAMP);
		}
		else if (!strcmp(text, "door")){
			printf(CHECK);
			printf(DOOR);
		}
	} while (strcmp(text,"exit")!=0);
	printf("Exit");
	return 0;
}

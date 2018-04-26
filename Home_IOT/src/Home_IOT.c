/*
 ============================================================================
 Name        : Home_IOT.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "./Utils/Interface.h"
#include "./Utils/Types.h"

int main(void) {
	int choice = -1;

	BOOL TV = OFF;
	BOOL AIRCON = OFF;
	BOOL LAMP = OFF;
	BOOL DOOR = OFF;

	do {
		interface();
		printf("MENU : ");
		scanf("%d", &choice);
		switch (choice) {
		case 0:
			break;
		case 1:
			TV = !TV;
			printf("TV : ");
			printf(TV ? "ON" : "OFF");
			break;
		case 2:
			AIRCON = !AIRCON;
			printf("AIRCON : ");
			printf(AIRCON ? "ON" : "OFF");
			break;
		case 3:
			LAMP = !LAMP;
			printf("LAMP : ");
			printf(LAMP ? "ON" : "OFF");
			break;
		case 4:
			DOOR = !DOOR;
			printf("DOOR : ");
			printf(DOOR ? "ON" : "OFF");
			break;
		}
	} while (choice != 10);
	printf("Exit");
	return EXIT_SUCCESS;
}

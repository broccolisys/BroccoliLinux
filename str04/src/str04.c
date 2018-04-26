/*
 ============================================================================
 Name        : str04.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void) {
	char a = 'a';
	char b = 'b';

	printf("upper : %c\n", toupper('a'));
	printf("lower : %c\n", tolower('B'));

	return EXIT_SUCCESS;
}

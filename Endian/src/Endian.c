/*
 ============================================================================
 Name        : Endian.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

 #include <stdio.h>
#include <stdlib.h>

int main(void) {
    char a[8]  = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};
    int  aa[2] = {0x01020304, 0x05060708};
    long aaa   = 0x0102030405060708;

    char* p = NULL;

    p = a;

    printf("\n---------------------\n");

    for(int i = 0; i < 8; i++) {
        printf("%02x ", *(p + i));
    }

    printf("\n---------------------\n");

    for(int i = 0; i < 8; i++) {
        printf("%02x ", p[i]);
    }

    p = aa;

    printf("\n---------------------\n");

    for(int i = 0; i < 8; i++) {
        printf("%02x ", p[i]);
    }

    p = &aaa;

    printf("\n---------------------\n");

    for(int i = 0; i < 8; i++) {
        printf("%02x ", p[i]);
    }

    printf("\n---------------------\n");

    return 0;
}

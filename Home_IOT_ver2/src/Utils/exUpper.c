#include <stdio.h>
#include <ctype.h>
#include "./exUpper.h"

void toupperstr(char* text){
	for (int i=0; i <= strlen(text); i++){
		text[i] = toupper(text[i]);
	}
}

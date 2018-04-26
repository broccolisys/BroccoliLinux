/*
 * exLower.c
 *
 *  Created on: 2018. 4. 26.
 *      Author: broccoli777
 */

#include <stdio.h>
#include <ctype.h>
#include "./exLower.h"

void tolowerstr(char* text){
	for (int i=0; i <= strlen(text); i++){
		text[i] = tolower(text[i]);
	}
}


#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "common.h"

/*
*	Useful function to substring a const char* string.
* This function is mainly used in the lexer
*/
char* substr(const char* string, int position, int length){
	char* pointer;
	int c;

	pointer = malloc(length + 1);

	for (c = 0; c < position; c++)	
		string++;

	for (c = 0; c < length; c++){
		*(pointer + c) = *string;
		string++;
	}

	*(pointer + c) = '\0';
	return pointer;
}

/*
*	Verify that the string passed is all an integer
*/
bool cobra_isInt(char* str){
	int i = 0;
	int len = strlen(str);
	while (isdigit(str[i++])){}
	return i == len;
}

/*
* Verifies that the word in the string says "false"
* or "true", then returns based on that.
*/
bool cobra_isBool(char* str){
	return strcmp(str, "true") == 0 || strcmp(str, "false") == 0;
}
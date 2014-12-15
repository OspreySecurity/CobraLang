
#include <stdlib.h>
#include "common.h"


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
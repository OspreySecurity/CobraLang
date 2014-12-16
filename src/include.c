#include <stdio.h>
#include "include.h"

void Cobra_Include(kInclude *inc, char* ch){
	FILE *fp;
	int count = 0;
	fp = fopen(inc->name,"r"); // read mode
	char c;
	if( fp == NULL )
	{
	  printf("%s\n", "error");
	}

	while( ( c = fgetc(fp) ) != EOF )
	  ch[count++] = c;

	fclose(fp);
}
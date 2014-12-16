

#ifndef PARSER_H_
#define PARSER_H_

#include "lexer.h"

void Parser(struct Lexer *lexer);
void Error(const char* msg, struct Lexer *lexer);
void ParseImport(struct Lexer *lexer);
void ParseInclude(struct Lexer *lexer);

typedef struct{
	char name[256];
} kImport;

typedef struct{
	char name[256];
} kInclude;

#endif // PARSER_H_
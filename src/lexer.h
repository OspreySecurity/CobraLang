

#ifndef LEXER_H_
#define LEXER_H_

#include <ctype.h>
#include "tokens.h"
#include "common/common.h"

/*
* Current information. Acts like an object
*/
struct Lexer{
	const char* source; // Source code goes here
	int size; // size of source
	int col;
	int row; 
	int pos;
	bool hasError; // Imported from common.h
	const char* errorMsg;
	int previousCol;
};

struct Token cobra_next_token(struct Lexer *lexer);
char cobra_next_char(struct Lexer *lexer);
char cobra_next_char_peek(struct Lexer* lexer);
char cobra_last_char(struct Lexer *lexer);

#endif // LEXER_H_
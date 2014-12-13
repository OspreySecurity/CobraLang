

#ifndef LEXER_H_
#define LEXER_H_

#include "tokens.h"

/*
* The basic token structure
*/
struct Token{
	int tok; // Taken from TOK from tokens.h
	char* value;
	int col; // Column the token starts
	int row; // Row which the token starts
	int pos; // Position from the start of the source string
};

struct Token cobra_next_token();

#endif // LEXER_H_
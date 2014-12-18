

#ifndef LEXER_H_
#define LEXER_H_

#include <ctype.h>
#include "tokens.h"
#include "common/common.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
* Current information. Acts like an object
*/
typedef struct{
	const char* source; // Source code goes here
	int size; // size of source
	int col;
	int row; 
	int pos;
	bool hasError; // Imported from common.h
	const char* errorMsg;
	int previousCol;
} Lexer;

void cobra_next_token(Lexer *lexer, Token* tok);
char cobra_next_char(Lexer *lexer);
char cobra_next_char_peek(Lexer* lexer);
char cobra_last_char(Lexer *lexer);
void cobra_set_token(Token* tok, int name, const char* value);

#ifdef __cplusplus
}
#endif

#endif // LEXER_H_
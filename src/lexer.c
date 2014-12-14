
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lexer.h"

/*
* Retrieves the next token
*/
struct Token cobra_next_token(struct Lexer *lexer){
	// Placeholder
	char letter = cobra_next_char(lexer);

	if (letter == -1){
		struct Token tok = {EOF_LITERAL, ""};
		return tok;
	}

	while (letter == ' ' && letter != -1) // skip spaces
		letter = cobra_next_char(lexer);

	if (isalpha(letter)){ // [a-zA-Z]
		int str_pos = 0;
		char str[256];
		str[str_pos++] = letter;

		letter = cobra_next_char(lexer);
		while (isalnum(letter) && letter != ' '){ // [a-zA-Z0-9]+
			str[str_pos++] = letter;
			letter = cobra_next_char(lexer);
		}
		const char* fstr = (const char*)str;

		if (strcmp(fstr, "var") == 0){
			struct Token tok = {VAR, "var"};
			return tok;
		}
		else{
			struct Token tok = {ID, fstr};
			return tok;
		}
	}

	struct Token tok = {EOF_LITERAL, ""};
	return tok;
}

/*
*	Retrieves the next char
*/
char cobra_next_char(struct Lexer *lexer){
	char letter = lexer->source[lexer->pos];

	if (letter == '\n'){ // skip new lines
		lexer->col = 0; // reset cols
		lexer->row++;
		lexer->pos++;
		return cobra_next_char(lexer);
	}
	else if (letter == '\0' || (lexer->pos) >= lexer->size){ // end of file
		return -1;
	}

	lexer->pos++;
	return letter;
}
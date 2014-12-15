
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
	if (letter == '\0'){
		struct Token tok = {EOF_LITERAL, ""};
		return tok;
	}

	while (letter == ' ' && letter != '\0') // skip spaces
		letter = cobra_next_char(lexer);

	if (isalpha(letter)){ // [a-zA-Z]
		int start = lexer->pos - 1; // position of first letter
		letter = cobra_next_char(lexer);
		while (isalnum(letter) && letter != ' ' && letter != '\0'){ // [a-zA-Z0-9]+
			letter = cobra_next_char(lexer);
		}

		int end = lexer->pos - 1; // position of last letter
		int len = end - start;
		char* str = substr(lexer->source, start, len); // found in common.c
		cobra_last_char(lexer); // reverse one char
		// Return the reserved word keyword
		if (strcmp(str, "import") == 0){
			struct Token tok = {IMPORT, "import"};
			return tok;
		}
		else if (strcmp(str, "include") == 0){
			struct Token tok = {INCLUDE, "include"};
			return tok;
		}
		else if (strcmp(str, "macro") == 0){
			struct Token tok = {MACRO, "macro"};
			return tok;
		}
		else if (strcmp(str, "var") == 0){
			struct Token tok = {VAR, "var"};
			return tok;
		}
		else if (strcmp(str, "return") == 0){
			struct Token tok = {RETURN, "return"};
			return tok;
		}
		else if (strcmp(str, "if") == 0){
			struct Token tok = {IF, "if"};
			return tok;
		}
		else if (strcmp(str, "else") == 0){
			struct Token tok = {ELSE, "else"};
			return tok;
		}
		else if (strcmp(str, "null") == 0){
			struct Token tok = {NULL_LITERAL, "null"};
			return tok;
		}
		else if (strcmp(str, "true") == 0){
			struct Token tok = {TRUE_LITERAL, "true"};
			return tok;
		}
		else if (strcmp(str, "false") == 0){
			struct Token tok = {FALSE_LITERAL, "false"};
			return tok;
		}
		else if (strcmp(str, "for") == 0){
			struct Token tok = {FOR, "for"};
			return tok;
		}
		else if (strcmp(str, "do") == 0){
			struct Token tok = {DO, "do"};
			return tok;
		}
		else if (strcmp(str, "while") == 0){
			struct Token tok = {WHILE, "while"};
			return tok;
		}
		else if (strcmp(str, "each") == 0){
			struct Token tok = {EACH, "each"};
			return tok;
		}
		else if (strcmp(str, "new") == 0){
			struct Token tok = {NEW, "new"};
			return tok;
		}
		else if (strcmp(str, "this") == 0){
			struct Token tok = {THIS, "this"};
			return tok;
		}
		else if (strcmp(str, "strict") == 0){
			struct Token tok = {STRICT, "strict"};
			return tok;
		}
		else if (strcmp(str, "try") == 0){
			struct Token tok = {TRY, "try"};
			return tok;
		}
		else if (strcmp(str, "catch") == 0){
			struct Token tok = {CATCH, "catch"};
			return tok;
		}
		else if (strcmp(str, "finally") == 0){
			struct Token tok = {FINALLY, "finally"};
			return tok;
		}
		else if (strcmp(str, "throw") == 0){
			struct Token tok = {THROW, "throw"};
			return tok;
		}
		else{
			struct Token tok = {ID, str};
			return tok;
		}
	}
	if (isdigit(letter)){
		int start = lexer->pos - 1;
		letter = cobra_next_char(lexer);

		while (isdigit(letter) || letter == '.')
			letter = cobra_next_char(lexer);

		char* str = substr(lexer->source, start, (lexer->pos - start - 1));
		cobra_last_char(lexer); // reverse one char
		struct Token tok = {RETURN_NUM, str};
		return tok;
	}

	if (letter == '='){ // ==
		char peek = cobra_next_char_peek(lexer);
		if (peek == '='){
			cobra_next_char(lexer); // increment
			struct Token tok = {DOUBLE_EQUALS, "=="};
			return tok;
		}
		else{
			struct Token tok = {EQUALS, "="};
			return tok;
		}
	}
	else if (letter == '!'){
		char peek = cobra_next_char_peek(lexer);
		if (peek == '='){
			cobra_next_char(lexer); // increment
			struct Token tok = {NOT_EQUALS, "!="};
			return tok;
		}
		else{
			struct Token tok = {NOT, "!"};
			return tok;
		}
	}
	else if (letter == '<'){
		char peek = cobra_next_char_peek(lexer);
		if (peek == '='){
			cobra_next_char(lexer); // increment
			struct Token tok = {LESS_EQUALS, "<="};
			return tok;
		}
		else{
			struct Token tok = {LESS, "<"};
			return tok;
		}
	}
	else if (letter == '>'){
		char peek = cobra_next_char_peek(lexer);
		if (peek == '='){
			cobra_next_char(lexer); // increment
			struct Token tok = {GREATER_EQUALS, ">="};
			return tok;
		}
		else{
			struct Token tok = {GREATER, ">"};
			return tok;
		}
	}
	else if (letter == '|'){
		char peek = cobra_next_char_peek(lexer);
		if (peek == '|'){
			cobra_next_char(lexer); // increment
			struct Token tok = {OR, "||"};
			return tok;
		}
		else{
			// Not yet implemented
		}
	}
	else if (letter == '&'){
		char peek = cobra_next_char_peek(lexer);
		if (peek == '&'){
			cobra_next_char(lexer); // increment
			struct Token tok = {AND, "&&"};
			return tok;
		}
		else{
			// Not yet implemented
		}
	}
	else if (letter == '%'){
		struct Token tok = {MOD, "%"};
		return tok;
	}
	else if (letter == '+'){
		char peek = cobra_next_char_peek(lexer);
		if (peek == '+'){
			cobra_next_char(lexer);
			struct Token tok = {DOUBLE_PLUS, "++"};
			return tok;
		}
		else{
			struct Token tok = {PLUS, "+"};
			return tok;
		}
	}
	else if (letter == '-'){
		char peek = cobra_next_char_peek(lexer);
		if (peek == '-'){
			cobra_next_char(lexer);
			struct Token tok = {DOUBLE_MINUS, "--"};
			return tok;
		}
		else{
			struct Token tok = {MINUS, "-"};
			return tok;
		}
	}
	else if (letter == '/'){
		struct Token tok = {DIVIDE, "/"};
		return tok;
	}
	else if (letter == '*'){
		struct Token tok = {TIMES, "*"};
		return tok;
	}
	else if (letter == '('){
		struct Token tok = {LPAREN, "("};
		return tok;
	}
	else if (letter == ')'){
		struct Token tok = {RPAREN, ")"};
		return tok;
	}
	else if (letter == '{'){
		struct Token tok = {LBRACKET, "{"};
		return tok;
	}
	else if (letter == '}'){
		struct Token tok = {RBRACKET, "}"};
		return tok;
	}
	else if (letter == '['){
		struct Token tok = {LBRACE, "["};
		return tok;
	}
	else if (letter == ']'){
		struct Token tok = {RBRACE, "]"};
		return tok;
	}
	else if (letter == '#'){
		struct Token tok = {STATIC, "#"};
		return tok;
	}
	else if (letter == '@'){
		struct Token tok = {CONSTRUCTOR, "@"};
		return tok;
	}
	else if (letter == '$'){
		struct Token tok = {PROTOTYPE, "$"};
		return tok;
	}
	else if (letter == '^'){
		struct Token tok = {GLOBAL, "^"};
		return tok;
	}
	else if (letter == '\''){
		int start = lexer->pos;
		letter = cobra_next_char(lexer); // Eat the apostrophe

		while (letter != '\'' && letter != '\0'){
			letter = cobra_next_char(lexer);
		}
		cobra_last_char(lexer);
		int end = lexer->pos;
		char* str = substr(lexer->source, start, (end - start));
		cobra_next_char(lexer);
		struct Token tok = {RETURN_STR, str};
		return tok;
	}
	else if (letter == '"'){
		int start = lexer->pos;
		letter = cobra_next_char(lexer);

		while (letter != '"' && letter != '\0'){
			letter = cobra_next_char(lexer);
		}

		cobra_last_char(lexer);
		int end = lexer->pos;
		char* str = substr(lexer->source, start, (end - start));
		cobra_next_char(lexer);
		struct Token tok = {RETURN_STR, str};
		return tok;
	}
	else if (letter == ','){
		struct Token tok = {COMMA, ","};
		return tok;
	}
	else if (letter == '.'){
		struct Token tok = {PERIOD, "."};
		return tok;
	}
	else if (letter == ';'){
		struct Token tok = {SEMI, ";"};
		return tok;
	}
	else if (letter == ':'){
		struct Token tok = {COLON, ":"};
		return tok;
	}
	
	struct Token tok = {EOF_LITERAL, " "};
	return tok;
}

/*
*	Retrieves the next char
*/
char cobra_next_char(struct Lexer *lexer){
	char letter = lexer->source[lexer->pos];
	if (letter == '\n'){ // skip new lines
		lexer->previousCol = lexer->col;
		lexer->col = 0; // reset cols
		lexer->row++;
		lexer->pos++;
		return cobra_next_char(lexer);
	}
	else if (letter == '\0' || (lexer->pos) >= lexer->size){ // end of file
		return '\0';
	}
	else{
		lexer->col++;
		lexer->pos++;
		return letter;
	}
}

/*
* Reverses the letter grabbed
*/
char cobra_last_char(struct Lexer *lexer){
	char letter = lexer->source[lexer->pos - 1];
	if (letter == '\n'){
		lexer->col = lexer->previousCol;
		lexer->previousCol = lexer->col - 1;
		lexer->row--;
		lexer->pos--;
		return cobra_last_char(lexer);
	}
	else{
		lexer->col--;
		lexer->pos--;
		return letter;
	}
}

/*
*	Peeks but does not save the next char
*/
char cobra_next_char_peek(struct Lexer* lexer){
	char letter = lexer->source[lexer->pos];

	if (letter == '\n'){
		return cobra_next_char_peek(lexer);
	}
	else if (letter == '\0' || (lexer->pos >= lexer->size)){
		return -1;
	}
	return letter;
}
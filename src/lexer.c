
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lexer.h"

/*
*	Set the value of the token
*/
void cobra_set_token(Token* tok, int name, const char* value){
	tok->type = name;
	strcpy(tok->value, value);
	//tok->value = value;
}

/*
* Retrieves the next token
*/
void cobra_next_token(Lexer *lexer, Token* tok){
	// Placeholder
	char letter = cobra_next_char(lexer);
	if (letter == '\0')
		cobra_set_token(tok, EOF_LITERAL, "");

	while ((letter == ' ' || letter == '\t') && letter != '\0') // skip spaces
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
		if (strcmp(str, "import") == 0)
			cobra_set_token(tok, IMPORT, "import");
		else if (strcmp(str, "include") == 0)
			cobra_set_token(tok, INCLUDE, "include");
		else if (strcmp(str, "macro") == 0)
			cobra_set_token(tok, MACRO, "macro");
		else if (strcmp(str, "var") == 0)
			cobra_set_token(tok, VAR, "var");
		else if (strcmp(str, "short") == 0)
			cobra_set_token(tok, SHORT, "short");
		else if (strcmp(str, "bool") == 0)
			cobra_set_token(tok, BOOL, "bool");
		else if (strcmp(str, "char") == 0)
			cobra_set_token(tok, CHAR, "char");
		else if (strcmp(str, "int") == 0)
			cobra_set_token(tok, INT, "int");
		else if (strcmp(str, "float") == 0)
			cobra_set_token(tok, FLOAT, "float");
		else if (strcmp(str, "double") == 0)
			cobra_set_token(tok, DOUBLE, "double");
		else if (strcmp(str, "long") == 0)
			cobra_set_token(tok, LONG, "long");
		else if (strcmp(str, "return") == 0)
			cobra_set_token(tok, RETURN, "return");
		else if (strcmp(str, "if") == 0)
			cobra_set_token(tok, IF, "if");
		else if (strcmp(str, "else") == 0)
			cobra_set_token(tok, ELSE, "else");
		else if (strcmp(str, "null") == 0)
			cobra_set_token(tok, NULL_LITERAL, "null");
		else if (strcmp(str, "true") == 0)
			cobra_set_token(tok, TRUE_LITERAL, "true");
		else if (strcmp(str, "false") == 0)
			cobra_set_token(tok, FALSE_LITERAL, "false");
		else if (strcmp(str, "for") == 0)
			cobra_set_token(tok, FOR, "for");
		else if (strcmp(str, "do") == 0)
			cobra_set_token(tok, DO, "do");
		else if (strcmp(str, "while") == 0)
			cobra_set_token(tok, WHILE, "while");
		else if (strcmp(str, "each") == 0)
			cobra_set_token(tok, EACH, "each");
		else if (strcmp(str, "new") == 0)
			cobra_set_token(tok, NEW, "new");
		else if (strcmp(str, "this") == 0)
			cobra_set_token(tok, THIS, "this");
		else if (strcmp(str, "strict") == 0)
			cobra_set_token(tok, STRICT, "strict");
		else if (strcmp(str, "try") == 0)
			cobra_set_token(tok, TRY, "try");
		else if (strcmp(str, "catch") == 0)
			cobra_set_token(tok, CATCH, "catch");
		else if (strcmp(str, "finally") == 0)
			cobra_set_token(tok, FINALLY, "finally");
		else if (strcmp(str, "throw") == 0)
			cobra_set_token(tok, THROW, "throw");
		else
			cobra_set_token(tok, ID, str);
	}
	else if (isdigit(letter)){
		int start = lexer->pos - 1;
		letter = cobra_next_char(lexer);

		while (isdigit(letter) || letter == '.')
			letter = cobra_next_char(lexer);

		char* str = substr(lexer->source, start, (lexer->pos - start - 1));
		cobra_last_char(lexer); // reverse one char
		cobra_set_token(tok, RETURN_NUM, str);
	}
	else if (letter == '='){ // ==
		char peek = cobra_next_char_peek(lexer);
		if (peek == '='){
			cobra_next_char(lexer); // increment
			cobra_set_token(tok, DOUBLE_EQUALS, "==");			
		}
		else
			cobra_set_token(tok, EQUALS, "=");
	}
	else if (letter == '!'){
		char peek = cobra_next_char_peek(lexer);
		if (peek == '='){
			cobra_next_char(lexer); // increment
			cobra_set_token(tok, NOT_EQUALS, "!=");			
		}
		else
			cobra_set_token(tok, NOT, "!");
	}
	else if (letter == '<'){
		char peek = cobra_next_char_peek(lexer);
		if (peek == '='){
			cobra_next_char(lexer); // increment
			cobra_set_token(tok, LESS_EQUALS, "<=");			
		}
		else
			cobra_set_token(tok, LESS, "<");
	}
	else if (letter == '>'){
		char peek = cobra_next_char_peek(lexer);
		if (peek == '='){
			cobra_next_char(lexer); // increment
			cobra_set_token(tok, GREATER_EQUALS, ">=");			
		}
		else
			cobra_set_token(tok, GREATER, ">");
	}
	else if (letter == '|'){
		char peek = cobra_next_char_peek(lexer);
		if (peek == '|'){
			cobra_next_char(lexer); // increment
			cobra_set_token(tok, OR, "||");			
		}
		else{
			// Not yet implemented
		}
	}
	else if (letter == '&'){
		char peek = cobra_next_char_peek(lexer);
		if (peek == '&'){
			cobra_next_char(lexer); // increment
			cobra_set_token(tok, AND, "&&");			
		}
		else{
			// Not yet implemented
		}
	}
	else if (letter == '%')
		cobra_set_token(tok, MOD, "%");
	else if (letter == '+'){
		char peek = cobra_next_char_peek(lexer);
		if (peek == '+'){
			cobra_next_char(lexer);
			cobra_set_token(tok, DOUBLE_PLUS, "++");
		}
		else
			cobra_set_token(tok, PLUS, "+");
	}
	else if (letter == '-'){
		char peek = cobra_next_char_peek(lexer);
		if (peek == '-'){
			cobra_next_char(lexer);
			cobra_set_token(tok, DOUBLE_MINUS, "--");			
		}
		else
			cobra_set_token(tok, MINUS, "-");
	}
	else if (letter == '/')
		cobra_set_token(tok, DIVIDE, "/");
	else if (letter == '*')
		cobra_set_token(tok, TIMES, "*");
	else if (letter == '(')
		cobra_set_token(tok, LPAREN, "(");
	else if (letter == ')')
		cobra_set_token(tok, RPAREN, ")");
	else if (letter == '{')
		cobra_set_token(tok, LBRACKET, "{");
	else if (letter == '}')
		cobra_set_token(tok, RBRACKET, "}");
	else if (letter == '[')
		cobra_set_token(tok, LBRACE, "[");
	else if (letter == ']')
		cobra_set_token(tok, RBRACE, "]");
	else if (letter == '#')
		cobra_set_token(tok, STATIC, "#");
	else if (letter == '@')
		cobra_set_token(tok, CONSTRUCTOR, "@");
	else if (letter == '$')
		cobra_set_token(tok, PROTOTYPE, "$");
	else if (letter == '^')
		cobra_set_token(tok, GLOBAL, "^");
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
		cobra_set_token(tok, RETURN_STR, str);
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
		cobra_set_token(tok, RETURN_STR, str);
	}
	else if (letter == ',')
		cobra_set_token(tok, COMMA, ",");
	else if (letter == '.')
		cobra_set_token(tok, PERIOD, ".");
	else if (letter == ';')
		cobra_set_token(tok, SEMI, ";");
	else if (letter == ':')
		cobra_set_token(tok, COLON, ":");
	else
		cobra_set_token(tok, EOF_LITERAL, " ");	
}

/*
*	Retrieves the next char
*/
char cobra_next_char(Lexer *lexer){
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
char cobra_last_char(Lexer *lexer){
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
*	Peeks but does not save the next char's position
*/
char cobra_next_char_peek(Lexer* lexer){
	char letter = lexer->source[lexer->pos];

	if (letter == '\n'){
		return cobra_next_char_peek(lexer);
	}
	else if (letter == '\0' || (lexer->pos >= lexer->size)){
		return -1;
	}
	return letter;
}
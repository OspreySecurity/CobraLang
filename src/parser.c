
#include <stdio.h>
#include <string.h>
#include "parser.h"
#include "common/common.h"

void Parser(struct Lexer *lexer){
	struct Token tok = cobra_next_token(lexer); // pass the address of the lexer
	//Loop and grab each token till the end of the file
	while (tok.tok != EOF_LITERAL){

		if (lexer->hasError)
			break;

		if (tok.tok == IMPORT){
			ParseImport(lexer);
			if (lexer->hasError)
				break;
		}

		//printf("%s\n", tok.value);
		// This is where we'll sort everything into an AST tree
		tok = cobra_next_token(lexer);
	}

	if (lexer->hasError){
		printf("%d:%d - %s\n", lexer->row, lexer->col, lexer->errorMsg);
	}
}

void Error(const char* msg, struct Lexer *lexer){
	lexer->hasError = true;
	lexer->errorMsg = msg;
}

void ParseImport(struct Lexer *lexer){
	struct Token tok = cobra_next_token(lexer);
	if (tok.tok == RETURN_STR){
		kImport kimport; // Don't know what to do with this yet though
		strcpy(kimport.super.name, tok.value);
		printf("%s%s\n", "Import used: ", kimport.super.name);
	}
	else if (tok.tok == LBRACKET){
		tok = cobra_next_token(lexer);
		while (tok.tok == RETURN_STR){
			kImport kimport; // Don't know what to do with this yet though
			strcpy(kimport.super.name, tok.value);
			printf("%s%s\n", "Import used: ", tok.value);
			tok = cobra_next_token(lexer);
			if (tok.tok != SEMI){
				Error("Syntax error, expected ';'", lexer);
				break;
			}
			else{
				tok = cobra_next_token(lexer); // eat the ; and proceed
			}
		}
		if (tok.tok != RBRACKET)
			Error("Syntax error, expected }", lexer);
	}
	else{
		Error("Syntax error, expected string", lexer);
	}
}
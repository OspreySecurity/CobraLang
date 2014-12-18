/*
* Resources:
* Parser: http://www.tcx.be/blog/2007/wp10-adl-parser-2/
* The Shunting-yard algorithm: http://en.wikipedia.org/wiki/Shunting-yard_algorithm
* http://stackoverflow.com/questions/5853136/how-do-i-write-a-parser-in-c-or-objective-c-from-without-a-parser-generators
* json library: https://bitbucket.org/zserge/jsmn/src/19001fb4adb3914cd4f7584c828fa2e0ff7f4922/jsmn.h?at=default
*/

#include <stdio.h>
#include <string.h>
#include "parser.h"
#include "include.h"
#include "common/common.h"
#include "compiler.h"
#include "object.h"

void Parser(Context* context, Lexer *lexer){
	Token tok;
	cobra_next_token(lexer, &tok); // pass the address of the lexer
	//Loop and grab each token till the end of the file
	while (tok.type != EOF_LITERAL){
		if (lexer->hasError)
			break;
		if (tok.type == INCLUDE)
			ParseInclude(lexer, &tok);
		else if (tok.type == IMPORT)
			ParseImport(lexer, &tok);
		else if (tok.type == VAR)
			ParseVariable(lexer, &tok, context);

		if (context->try_catch.hasError)
			break;

		// This is where we'll sort everything into an AST tree
		cobra_next_token(lexer, &tok);
	}
}

void Error(const char* msg, Lexer *lexer, Context* context){
	lexer->hasError = true;
	lexer->errorMsg = msg;
	context->try_catch.hasError = true;
	sprintf(context->try_catch.msg, "%d:%d - %s", lexer->row, lexer->col, lexer->errorMsg);
}

void ParseInclude(Lexer* lexer, Token* tok){

}

void ParseImport(Lexer* lexer, Token* tok){
	
}

/*
*	function for parsing a variable
*/
void ParseVariable(Lexer* lexer, Token* tok, Context* context){
	cobra_next_token(lexer, tok);
	if (tok->type != ID && tok->type != LBRACKET)
		Error("Invalid declaration of variable", lexer, context);
	else{
		if (tok->type == ID){
			kObject var;
			cobra_set_object(&var, tok->value, "var"); // store the name and the type
			
			cobra_next_token(lexer, tok);
			if (tok->type != EQUALS)
				Error("Syntax error, missing '='", lexer, context);
		}
		else{
			while (tok->type != RBRACKET){
				ParseVariable(lexer, tok, context);
				if (context->try_catch.hasError)
					break;
			}
		}
	}
	cobra_next_token(lexer, tok);
	if (tok->type != SEMI && !context->try_catch.hasError)
		Error("Syntax error, missing ';'", lexer, context);
}
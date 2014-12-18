
#include <string.h>
#include <stdio.h>
#include "compiler.h"
#include "parser.h"

/*
*	This is where the magic begins. Pass in the source code, 
* the name of the code, and watch the magic happen.
* Example:
* 	Cobra_Compile(Context* context, "var i = 10;", "inline");
*/
void Cobra_Compile(Context* context, const char* source, const char* name){
	// Grab the initial toke
	Lexer lexer = {source, (int)strlen(source), 0, 1, 0, 0, ""};

	Parser(context, &lexer);
	if (context->try_catch.hasError)
		printf("%s\n", context->try_catch.msg);
}
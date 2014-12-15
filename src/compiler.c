
#include <string.h>
#include "compiler.h"
#include "parser.h"

void Cobra_Compile(const char* source, const char* name){
	// Grab the initial toke
	struct Lexer lexer = {source, (int)strlen(source), 0, 0, 0, 0, ""};

	Parser(&lexer);
}


#include "compiler.h"

void Cobra_Compile(const char* source, const char* name){
	// Grab the initial token
	struct Token nextTok = cobra_next_token();

	// Loop and grab each token till the end of the file
	while (nextTok.tok != EOF_LITERAL){
		// This is where we'll sort everything into an AST tree
		nextTok = cobra_next_token();
	}
}


#include "compiler.h"

void Cobra_Compile(const char* source, const char* name){
	// Grab the initial token
	struct Lexer lexer = {source, sizeof(source), 0, 0, 0, 0, ""};

	struct Token nextTok = cobra_next_token(&lexer); // pass the address of the lexer
	//Loop and grab each token till the end of the file
	while (nextTok.tok != EOF_LITERAL){
		printf("%s\n", nextTok.value);
		// This is where we'll sort everything into an AST tree
		nextTok = cobra_next_token(&lexer);
	}
}


#ifndef PARSER_H_
#define PARSER_H_

#include "lexer.h"
#include "context.h"

#ifdef __cplusplus
extern "C" {
#endif

void Parser(Context* context, Lexer *lexer);
void Error(const char* msg, Lexer *lexer, Context* context);
void ParseInclude(Lexer* lexer, Token* tok);
void ParseImport(Lexer* lexer, Token* tok);
void ParseVariable(Lexer* lexer, Token* tok, Context* context);
void ParseExpression(Lexer* lexer, Token* tok, Context* context);

#ifdef __cplusplus
}
#endif

#endif // PARSER_H_


#ifndef COMPILER_H_
#define COMPILER_H_

#include "lexer.h"
#include "tokens.h"
#include "context.h"

#ifdef __cplusplus
extern "C" {
#endif

void Cobra_Compile(Context* context, const char* source, const char* name);

#ifdef __cplusplus
}
#endif

#endif // COMPILER_H_
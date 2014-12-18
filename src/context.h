

#ifndef CONTEXT_H_
#define CONTEXT_H_

#include "common/common.h"
#include "try_catch.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct{
	Try_Catch try_catch;
} Context;

void context();

#ifdef __cplusplus
}
#endif

#endif // CONTEXT_H_


#ifndef TRY_CATCH_H_
#define TRY_CATCH_H_

#include "common/common.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct{
	bool hasError;
	char* msg;
} Try_Catch;

#ifdef __cplusplus
}
#endif

#endif // TRY_CATCH_H_
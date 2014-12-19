

#ifndef COMMON_H_
#define COMMON_H_

#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
*	Bool isn't defined in C, but now it is!
*/
typedef int bool;
#define true 1;
#define false 0;

char* substr(const char* str, int start, int length);
bool cobra_isInt(char* str);
bool cobra_isBool(char* str);

#ifdef __cplusplus
}
#endif

#endif // COMMON_H_
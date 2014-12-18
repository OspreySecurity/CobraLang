

#ifndef OBJECT_H_
#define OBJECT_H_

#include "common/common.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
*	The object structure
*/
typedef struct{
	char name[256]; // The name of the variable
	char type[10]; // The type of the variable as a string
	bool isString;
	bool isFunction;
	bool isChar;
	bool isInt;
	bool isFloat;
	bool isBool;
} kObject;

void cobra_set_object(kObject* obj, char* value, const char* type);
void cobra_get_object_type(kObject* obj, char* value);
void cobra_set_object_value(kObject* obj, char* value);

#ifdef __cplusplus
}
#endif

#endif // OBJECT_H_


#ifndef COBRA_H_
#define COBRA_H_

/*
*	Bool isn't defined in C, but now it is!
*/
typedef int bool;
#define true 1;
#define false 0;

/*
*	The context struct
*/
typedef struct{
	bool hasError;
} Context;

/*
* The API is fairly simple. Compile const char* of code
* into the cobra language. 
*/
void Cobra_Compile(Context* context, const char* code, const char* name);

#endif // COBRA_H_
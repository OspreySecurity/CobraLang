#include <string.h>
#include "object.h"
#include "tokens.h"

/*
*	Setting values in the cobra object. Objects are the base type
* of all items in the Cobra language.
*/
void cobra_set_object(kObject* obj, char* name, const char* type){
	strcpy(obj->name, name);
	obj->isString = false;
	obj->isFunction = false;
	obj->isChar = false;
	obj->isInt = false;
	obj->isFloat = false;
	obj->isBool = false;
	strcpy(obj->type, type);
}

/*
*	Essentially, this will call the function, cobra_get_object_type 
* and set the value based on the type
*/
void cobra_set_object_value(kObject* obj, char* value){
	cobra_get_object_type(obj, value);
}

/*
* Used to get the object's type based on the value.
* This is the factory in which we search through the
* value and determin the type.
*/
void cobra_get_object_type(kObject* obj, char* value){
	if (cobra_isInt(value)){
		obj->isInt = true;
	}
	else if (cobra_isBool(value)){
		obj->isBool = true;	
	}			
}	
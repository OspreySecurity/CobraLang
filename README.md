CobraLang
=========

Another efficient, simple, easy, and robust programming language

Concepts
--------

Include another file an compile into context:
```
include "filename"
```
 - Extension of the file is not needed
 - File should be relative to where the program was launched.
 - using the ~/ represents where the init directory is
 - includes can happen anywhere in the file and by dynamically included during runtime

Include another module, included with the language:
```
import "os"
```
 - module names are all lowercased
 - modules imported are assigned to that variable name
 - i.e. import "os" is assigned var os
 - imports can happen anywhere in the file and by dynamically included during runtime

Imports and includes can be declared in bulk
```
import{
  "os";
  "fs";
}

include{
  "filename"
  "anotherFileName";
}
```

Macros 
```
macro MAX_FILE_SIZE 40000;
macro BUFFER_SIZE 2000;
```
 - macro names are to always be upper case
 - macros can be a variable, object, or function

Macros can be declared in bulk
```
macro{
  MAX_FILE_SIZE 40000;
  BUFFER_SIZE 2000;
}
```

Variables
```
var variableName = 10;
int varName = 10;
char letter = 'a';
var letter = 'a';
```
 - The keyword var can be used instead of data type
 - variable names follow this pattern: [a-zA-Z][a-zA-Z0-9]*

Variables can be declared in bulk
```
var {
  variableName;
  variableName2 = 1;
  variableName3 = 'a';
}

int {
  variableName = 1;
  variableName2 = 2;
}
```

Objects
```
objectName{
  ...
}
```
 - Object names follow the same rules as far as variable naming pattern: [a-zA-Z][a-zA-Z0-9]*
 - The curly braces are required at the beginning and end
 - Objects cannot be declared in bulk
 - Object names must not be a reserved word

Object constructors
Single constructor
```
objectName{
  @name;
}

var obj = new objectName('frank');
```
Bulk constructors
```
objectName{
  @{
    name;
    size;
    weight;
  }
}

var obj = new objectName('frank', 65, 175);
```
 - Constructors will be required at the creation of an object
 - Constructor orders will be required from top to bottom
 - Constructor values will be set to null if no value is pass through

Static value
```
math{
  #pi = 3.14159265;
  #mult(x, y){
    return x * y;
  }
}

var pi = math.pi;
var value = math.mult(10, 20);
```
 - Static values can be of any type
 - Static values are used in includes

Static values in included files
```
// mathFunctions.cb
var unseenValue = 100;

#math{
  #pi = 3.14159265;
  #mult(x, y){
    return x * y;
  }
}

// main.cb
include "mathFunctions"
var pi = math.pi;
var val = unseenValue;
// (error) undeclared variable "unseenValue"
```

Bulk declare static values
```
objectName{
  #{
    name = 'Frank';
    size = 100;
    weight 175;
  }
}
```

Add an object property
```
objectName{
  this.propertyName;
}

var obj = new objectName();
obj.propertyName;
```
 - To declare a single non-constructor, non-static property name needs the word this
 - The property can be of any type

To add a prototype method or variable to an object
```
objectName{
  this.name = 'Franklynn';
}

$objectName.weight = 175;
```
 - Prototype methods are required to start with the dollar sign followed by the object name then the desired prototype property name
 - Prototype methods are powerful because they are pointers to that object. If it's not a prototype method, the property and value will be recreated each time there is a new instance of the object.

Prototypes in bulk
```
$objectName{
  name = 'Franklynn';
  weight = 175;
}
```

Functions and methods
```
functionName(a, b){
  var x = 10;
  return a * b * x;
}

y(n){
  return n / 10;
}
```
 - Function names must not be any reserved words
 - Functions cannot be declared in bulk

Global variables
```
var variableName = 100;
```

To access a global variable in a method or function
```
var variableName = 100;
getName(){
  return ^variableName;
}
```
 - The carret is the only way to access a global variable
 - variables with the same name as a global variable will only be used within their scope

To change the global variables value
```
var variableName = 100;
changeValue(){
  ^variableName = 101;
}
```

To be safe, we included the strict keyword to prevent accidental global varible manipulations
```
var variableName = 100;
computeValue(){
  strict;
  ^variableName = 101;
  (error) Undefined variable "variableName"
}
```

Declare Object:
```
// Include your own file with or without extension
include "filename";

// include module
import "os";

// Required to be upper cased
macro MAX_SIZE 10;

var globalVariable = 10;

object{
  @property; // Part of constructor
  
  //Multiple constructors
  @{
    size;
    weight;
  }
  
  #name = "Person Object"; // Static property, method, etc...
  
  // Multiple Static
  #{
    name;
    length;
  }
  
  // Typical object property
  this.anotherProperty;
  
  var prop = "Hidden"; // Private value
  
  // Declare multiple variables
  var{
    name;
    size;
  }
  
  // Declare multiple of same type
  int{
    weight;
    height;
  }
  
  method(){
    // does not replace the global variable
    var globalVariable = 12;
    
    // Replaces the global variable;
    ^globalVariable = 11;
  }
  
  method2(){
    // will never access any outside variables
    strict;
    
    var globalVariable = 12;
  }
}

// Add single prototype
$object.method(){

}

// Add prototypes to the object in bulk
$object{
  methodName(){
    ...
  }
}

// Declare the object and call a method
var newObj = new object(10, 20);
newObj.method();

// % = mixed array
ary[
  1,
  '2',
  3.0,
  new object()
]

// Access a particular index
var o = ary[3];

// Filter to types
var allObjects[] = ary.filter('object');

Pointers
method1(){}

// Declare pointer
var methodPointer -> method1;

// Dereference the pointer
methodPointer*;
```

Declare Function
```
getName(){
  return "Daren";
}
```

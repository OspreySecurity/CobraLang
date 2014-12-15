#include "compiler.h"

int main(int argc, const char* argv[]){
	const char* code = "import 'os';\n"
										 "math{\n"
										 "#pi = 3.14159265;"
										 "add(x,y){"
										 "  return x + y;"
										 "}"
										 "}";
	Cobra_Compile(code, "inline");
  return 0;
}

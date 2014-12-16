#include "compiler.h"

int main(int argc, const char* argv[]){
	const char* code = "import {"
										 "'os';"
										 "'fs';"
										 "}"
										 "include 'build/test.cb'";
	Cobra_Compile(code, "inline");
  return 0;
}

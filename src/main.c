#include "compiler.h"

int main(int argc, const char* argv[]){
	Cobra_Compile("var i = 'a';", "inline");
  return 0;
}

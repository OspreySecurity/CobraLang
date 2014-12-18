#ifdef __cplusplus
extern "C" {
#endif

#include <cobra.h>

int main(int argc, const char* argv[]){
	Context context;
	const char* code = "var{"
										 "	i = 0;"
										 "  j = 10;"
										 "  t = 'a'"
										 "}";
	Cobra_Compile(&context, code, "inline");
  return 0;
}

#ifdef __cplusplus
}
#endif
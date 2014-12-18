#ifdef __cplusplus
extern "C" {
#endif

#include <cobra.h>
#include <string.h>

int main(int argc, const char* argv[]){
	Context context;
	if (argc > 1){
		char str[256];
		strcpy(str, argv[1]);

		for (int i = 2; i < argc; ++i)
		{
		  strcat(str, " ");
		  strcat(str, argv[i]);
		}
		Cobra_Compile(&context, str, "shell");
	}
	else{
		const char* code = "var{\n"
											 "	i = 0;\n"
											 "  j = 10;\n"
											 "  t = 'a';\n"
											 "};";
		Cobra_Compile(&context, code, "inline");
	}
  return 0;
}

#ifdef __cplusplus
}
#endif
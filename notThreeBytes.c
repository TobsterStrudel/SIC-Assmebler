#include "headers.h"

int IsThreeBytes(char *Test){

	return((
		strcmp(Test, "START") &&
	//	strcmp(Test, "BYTE") && // WHY DOES THIS BREAK IT
	//	strcmp(Test, "WORD") &&
		strcmp(Test, "RESB") &&
		strcmp(Test, "RESW")
		));
}

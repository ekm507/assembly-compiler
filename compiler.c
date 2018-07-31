/* Assembly compiler for "The 16-bit CPU"
*  compiler.c
*  compile function
*/

#include "compiler.h"
#include "clean-code.h"
#include <stdio.h>

int compile(char* code, unsigned long int size)
{
	//remove all comments and useless newline or space characters.
	size = cleancode(code, size);

	//print the cleaned code.
	unsigned long int i;
	for(i = 0; i < size; i++)
		printf("%c", code[i]);

	//returns 0 if there are no errors.
	return 0;
}

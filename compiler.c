/* Assembly compiler for "The 16-bit CPU"
*  compiler.c
*  compile function
*/

#include "compiler.h"
#include "read_write.h"
#include <stdio.h>

int compile(char* filename, char* outputfilename)
{
	//open the source file and load it to code variable
	char *code;
	int status = -1;
	status = read(filename, code);
	if(!status)
		return -1;

	//returns 0 if there are no errors.
	return 0;
}

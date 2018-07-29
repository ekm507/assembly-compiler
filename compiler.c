/* Assembly compiler for "The 16-bit CPU"
*  compiler.c
   compile function
*/

#include "compiler.h"
#include <stdio.h>

int compile(char* filename, char* outputfilename)
{
	//open the soyrce code file
	FILE *codefile;
	codefile = fopen(filename, "r");
	if(codefile == NULL)
	{
		perror("error openinig file\n");
		return -1;
	}


	return 0;
}

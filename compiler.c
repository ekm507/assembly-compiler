
#include "compiler.h"
#include <stdio.h>

int compile(char* filename, char* outputfilename)
{
	FILE *codefile;
	codefile = fopen(filename, "r");
	if(codefile == NULL)
	{
		perror("error openinig file\n");
		return -1;
	}


	return 0;
}

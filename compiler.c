/* Assembly compiler for "The 16-bit CPU"
*  compiler.c
*  compile function
*/

#include "compiler.h"
#include <stdio.h>

int compile(char* code, unsigned long int size)
{
	char words[1000][3][10];
	int j = 0, k = 0, p = 0;;
	for(int i = 0; i < size; i++)
	{
		if(code[i] == 10)
		{
			while(code[i++] == 10);
			j++;
			k = 0;
			p = 0;
		}
		else if(code[i] == 32)
		{
			while(code[i++] == 32);
			if(code[i] != ';' || 
code[i] != 10)
			{
				p++;
				k = 0;
			}
		}
		else if(code[i] == ';')
			while(code[i++]!=10);
		else
			words[j][p][k++] = code[i];
	}
	for(int hh = 0; hh<j; hh++)
		printf("%s\n", words[hh][1]);
	//returns 0 if there are no errors.
	return 0;
}

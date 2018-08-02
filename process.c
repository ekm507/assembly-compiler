/* Assembly compiler for "The 16-bit CPU"
*  process.c
*  process function
*/

#include "process.h"
#include "clean-code.h"
#include "check.h"
#include "errors.h"
#include <stdio.h>
#include <stdlib.h>


//process the code and compile it using compile function
int process(char* code, unsigned long int size, FILE *outputfile)
{


	//remove all comments and useless newline or space characters.
	size = cleancode(code, size);

	char array[5][10] = {"", "", "", "", ""};
	unsigned long int line = 0;
	int word = 0;
	int wordchar = 0;
	for(unsigned long int i = 0; i < size; i++)
	{
		if(word < 4)
		{
			if(code[i] == ' ')
			{
				array[word][wordchar+1] = '\0';
				word++;
				wordchar = 0;
			}
			else if(code[i] == '\n')
			{
				array[word][wordchar+1] = '\0';
				word = 0;
				wordchar = 0;
				check(array);
				strcpy(array[4], "");
			}
			else
				array[word][wordchar] = code[i];
		}
		else
		{
			send_error(0);
			while(i++ != '\n' && i < size);
			i--;
		}
	}

	//returns 0 if there are no errors.
	return 0;
}

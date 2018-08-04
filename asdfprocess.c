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
	unsigned long int line = 1;
	int word = 1;
	int wordchar = 0;
	for(unsigned long int i = 0; i < size; i++)
	{
		if(word < 5)
		{
			if(code[i] == ' ')
			{
				array[word][wordchar] = '\0';
				wordchar = 0;
				word++;
			}
			else if(code[i] == '\n')
			{
				array[word][wordchar] = '\0';
				word = 1;
				wordchar = 0;
				//check if there is any bug
				check(array, line);
				line++;
				strcpy(array[1], "");
				strcpy(array[2], "");
				strcpy(array[3], "");
				strcpy(array[4], "");
			}
			else
				array[word][wordchar] = code[i];
		}
		else
		{
			send_error(0, line, array); //ERROR # 0
			while( (++i != '\n') && (i < size) );
			if(i < size)
				i--;
			word = 1;
		}

		wordchar++;
	}

	//returns 0 if there are no errors.
	return 0;
}

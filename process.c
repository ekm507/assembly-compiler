/* Assembly compiler for "The 16-bit CPU"
*  process.c
*  process function
*/

#include "compiler.h"
#include "process.h"
#include "clean-code.h"
#include <stdio.h>
#include <stdlib.h>

//process the code and compile it using compile function
int process(char* code, unsigned long int size, FILE *outputfile)
{
	//remove all comments and useless newline or space characters.
	size = cleancode(code, size);

	//count the words
	unsigned long int number_of_words;
	number_of_words = wordcount(code, size);

	//alloc words array
	char *words[10];
	for(unsigned long int i = 0; i < number_of_words; i++)
		words[i] = (char*)malloc(number_of_words * sizeof(char) );

	//load the code to words array(word by word)
	chartoword(code, size, words);

	//free char code array
	free(code);

	//compile the code
	compile(words, number_of_words, outputfile);

	//print the cleaned code.
	unsigned long int i;
	for(i = 0; i < number_of_words; i++)
		printf("%s ", words[i]);

	//free the words code array
	free(words);

	//returns 0 if there are no errors.
	return 0;
}

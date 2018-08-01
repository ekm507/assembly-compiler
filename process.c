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

	int max_word_length = 10;
	int max_words_in_a_line = 4;

	//remove all comments and useless newline or space characters.
	size = cleancode(code, size);

	//count the words
	unsigned long int number_of_words;
	number_of_words = wordcount(code, size);

	//alloc words array
	char *words;
	words = (char*)malloc(number_of_words *max_word_length * max_words_in_a_line  * 
sizeof(char) );

	//load the code to words array(word by word)
	chartoword(code, size, words);

	//free char code array
	free(code);

	//compile the code
	compile(words, number_of_words, outputfile);

	//print the cleaned code.
	unsigned long int i;
	for(i = 0; i < number_of_words; i++)
	{
		for(int j = 0; j < 10; j++)
			printf("%c", words[i * 10 + j]);
		printf("-");
	}

	//free the words code array
	free(words);

	//returns 0 if there are no errors.
	return 0;
}

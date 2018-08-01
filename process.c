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

	//we will store length of any word in this array
	int *words_length;
	words_length = (int*)malloc(number_of_words * sizeof(int));

	//load words lengths into array.
	measure_words_length(code, size, words_length);

	//code will be stored in this array word-by-word
	char **words;

	//allocate words array [number of words]
	words = (char**)malloc(number_of_words * sizeof(char*));
	//allocate words array [words length for each word]
	for(unsigned long int i = 0; i < number_of_words; i++)
		words[i] = (char*)malloc( (words_length[i] + 1) * sizeof(char));
		/* notice :( words_lenght[i] + 1) :				 *
		 *  word length is added by 1 to be space for the '\0' character */


	//free wordslength array
	free(words_length);

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
	for(unsigned long int i = 0; i < number_of_words; i++)
		free(words[i]);
	free(words);

	//returns 0 if there are no errors.
	return 0;
}

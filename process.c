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

	//count number of words
	unsigned long int number_of_words;
	number_of_words = wordcount(code, size);

	//measure size of each word
	int *words_length;
	words_length = (int *)malloc(number_of_words * sizeof(int) );
	measure_words_length(code, size, words_length);

	//count number of lines in the code.
	unsigned long int number_of_lines;
	number_of_lines = countlines(code, size);

	//words_in_line will contain number of words in each line.
	int *words_in_line;
	words_in_line = (int *)malloc(number_of_lines * sizeof(int) );

	//number of words in each line will be stored here
	//load number of words in each line to array
	countwords(code, size, words_in_line);

	//code will be stored in this array word-by-word
	char **words;

	//allocate words array words[a][b]
	//a : number of word
	//b : word
	words = (char **)malloc((number_of_lines + number_of_words) * sizeof(char *));
	int word_of_line = 0;
	unsigned long int line = 0;
	for(unsigned long int i = 0; i < number_of_lines + number_of_words; i++)
	{
		words[i] = (char *)malloc(words_in_line[i] * sizeof(char) );
		if(++word_of_line >= words_in_line[line])
		{
			words[++i] = (char *)malloc(2 * sizeof(char) );
			word_of_line = 0;
			line++;
		}
	}

	//load words into words array.
	loadwords(code, size, words);

	//free wordslength array
	free(words_length);

	//free char code array
	free(code);

	//compile the code
	compile(words, number_of_lines, words_in_line, outputfile);

	//print number of words in each line
	for(unsigned long int i = 0; i < number_of_lines; i++)
		printf("%lu %d\n", i, words_in_line[i]);

	//print the cleaned code.
	unsigned long int i;
	for(i = 0; i < number_of_lines + number_of_words; i++)
		printf("%s ", words[i] );

	//free the words code array
	for(unsigned long int i = 0; i < number_of_words + number_of_lines; i++)
		free(words[i]);
	free(words);

	//free words_in_line
	free(words_in_line);

	//returns 0 if there are no errors.
	return 0;
}

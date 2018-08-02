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

	//number of words in each line will be stored here
	int *words_in_line;

	//number of lines in the code
	unsigned long int number_of_lines;

	//count number of lines in the code.
	number_of_lines = countlines(code, size);

	//allocate memory for words-in_line
	words_in_line = (int *)malloc(number_of_lines * sizeof(int) );

	//load number of words in each line to array
	countwords(code, size, words_in_line);

	//code will be stored in this array word-by-word
	char ***words;

	//allocate words array [number of words]
	words = (char***)malloc(number_of_lines * sizeof(char**));

	//allocate words array [words length for each word - number of words for each line]
	unsigned long int wordnumber = 0;
	for(unsigned long int i = 0; i < number_of_lines; i++)
	{
		words[i] = (char**)malloc(words_in_line[i] * sizeof(char*) );
		for(unsigned long int j = 0; j < words_in_line[i]; j++)
		{
			words[i][j] = (char*)malloc( (words_length[wordnumber] + 1) 
* sizeof(char));
			wordnumber++;
		/* notice :( words_lenght[wordnumber] + 1) :				 *
		 *  word length is added by 1 to be space for the '\0' character */
		}
	}

	//load words into words array.
	loadwords(code, size, words);


	//free wordslength array
	free(words_length);

	//free char code array
	free(code);

	//compile the code
	compile(words, number_of_words, outputfile);

	//print the cleaned code.
	unsigned long int i;
	for(i = 0; i < number_of_lines; i++)
	{
		for(int j = 0; j < 10; j++)
			printf("%c", words[i * 10 + j]);
		printf("-");
	}

	//free the words code array
	for(unsigned long int i = 0; i < number_of_words; i++)
	{
		for(unsigned long int j = 0; j < words_in_line[i]; j++)
			free(words[i][j]);
		free(words[i]);
	}
	free(words);

	//free words_in_line
	free(words_in_line);

	//returns 0 if there are no errors.
	return 0;
}

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
	char ***words;

	//allocate words array words[a][b][c]
	// a = [number of lines in this code]
	// b = [number of words in each line]
	// c = [number of chars in each word]
	words = (char***)malloc(number_of_lines * sizeof(char**));
	unsigned long int wordnumber = 0;
	for(unsigned long int i = 0; i < number_of_lines; i++)
	{
		words[i] = (char**)malloc(words_in_line[i] * sizeof(char*) );
		for(unsigned long int j = 0; j < words_in_line[i]; j++)
		{
			words[i][j] = (char*)malloc( (words_length[wordnumber] + 1) * sizeof(char));
			wordnumber++;
		/* notice :( words_lenght[wordnumber] + 1) :			 *\
		\*  word length is added by 1 to be space for the '\0' character */
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

	//print the cleaned code.
	unsigned long int i;
	for(i = 0; i < number_of_lines; i++)
	{
		for(int j = 0; j < words_in_line[i]; j++)
			printf("%s", words[i][j] );
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

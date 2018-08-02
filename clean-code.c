#include "clean-code.h"
#include <stdio.h>


unsigned long int cleancode(char* code, unsigned long int size)
{
	unsigned long int i;

	//level.1 : delete comments
	for(i = 0; i < size - 1; i++)
	{
		if(code[i] == ';')
		{
			while(code[++i] != '\n' && i < size)
				code[i] = ';';
		}
	}

	//level.2 : convert \t (tab) characters to '  (space) character
	for(i = 0; i < size; i++)
		if(code[i] == '\t')
			code[i] = ' ';

	//level.3 : delete useless newline characters and useless space characters that come
	//after newline characters.
	for(i = 0; i < size - 1; i++)
	{
		if(code[i] == '\n')
		{
			while( ( code[++i] == '\n' || code[i] == ';' || code[i] == ' ' ) && i 
< size)
				code[i] = ';';
			i--;
		}
	}
	if(code[size - 1] == '\n' || code[size - 1] == ' ')
		code[size - 1] = ';';

	//level.4 : delete useless space characters
	for(i = 0; i < size; i++)
	{
		if(code[i] == ' ')
		{
			while(code[++i] == ' ' && i < size)
				code[i] = ';';
			i--;
		}
	}

	//level 5 : delete space chaacters that come before newline character
	for(i = 0; i < size; i++)
		if(code[i] == '\n')
		{
			int j = i;
			while(code[--j] == ';');
			if(code[j] == ' ')
				code [j] = ';';
		}

	//level.6 : clear all created ';'
	unsigned long int j = 0;
	for(i = 0; i < size - 1; i++)
	{
		if(code[i] != ';')
			code[ j++ ] = code[i];
	}
	//finish :)

	//return new code size.
	return j;
}

//-----------------------------------------------------------------------------------------//

unsigned long int wordcount(char *code, unsigned long int size)
{
	if(size == 0)
		return 0;

	unsigned long int number_of_words = 1;
	for(unsigned long int i = 0; i < size; i++)
		if(code[i] == '\n' || code[i] == ' ')
			number_of_words++;
	return number_of_words;
}


//---------------------------------------------------------------------------------------//

void measure_words_length(char *code, unsigned long int size, int *words_length)
{
	//length of the current word
	int k = 0;
	//number of the current word
	int j = 0;

	for(unsigned long int i = 0; i < size; i++)
	{
		if(code[i] == '\n' || code[i] == ' ')
		{
			words_length[j++] = k;
			k = 0;
		}
		else
			k++;
	}
}

//---------------------------------------------------------------------------------------//

void loadwords(char *code, unsigned long int size, char ***words)
{

	int max_word_length = 10;
	int max_words_in_a_line = 4;

	int line = 0;
	int word_in_line = 0;
	int wordchar = 0;

	for(unsigned long int i = 0; i < size; i++)
		if(code[i] == '\n')
		{
			line++;
			word_in_line = 0;
			wordchar = 0;
		}
		else if(code[i] == ' ')
		{
			words[line][word_in_line][wordchar + 1] = '\0';
			word_in_line++;
			wordchar = 0;
		}
		else
		{
			words[line][word_in_line][wordchar] = code[i];
			wordchar++;
		}

}

//---------------------------------------------------------------------------------------//

unsigned long int countlines(char *code, unsigned long int size)
{
	unsigned long int lines = 0;
	for(unsigned long int i = 0; i < size; i++)
		if(code[i] == '\n')
			lines++;

	return lines;
}

//---------------------------------------------------------------------------------------//

void countwords(char *code, unsigned long int size, int *words_in_line)
{
	unsigned long int line = 0;
	words_in_line[0] = 0;

	for(unsigned long int i= 0; i < size; i++)
		if(code[i] == ' ')
			words_in_line[line]++;
		else if(code[i] == '\n')
		{
			words_in_line[line]++;
			words_in_line[++line] = 0;
		}
}

//---------------------------------------------------------------------------------------//


//---------------------------------------------------------------------------------------//


//---------------------------------------------------------------------------------------//

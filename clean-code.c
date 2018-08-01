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
			while(code[++i] != '\n' && i < size) // ASCII 10 = newline
				code[i] = ';';
		}
	}

	//level.2 : delete useless newline characters and useless space characters that come
	//after newline characters.
	for(i = 0; i < size - 1; i++)
	{
		if(code[i] == 10) //ASCII 10 = newline
		{
			while( ( code[++i] == 10 || code[i] == ';' || code[i] == ' ' ) && i < size)
				code[i] = ';';
			i--;
		}
	}
	if(code[size - 1] == 10 || code[size - 1] == ' ')
		code[size - 1] = ';';

	//level.3 : delete useless space characters
	for(i = 0; i < size; i++)
	{
		if(code[i] == ' ')
		{
			while(code[++i] == ' ' && i < size)
				code[i] = ';';
			i--;
		}
	}

	//level 3.5 : delete space chaacters that come before newline character
	for(i = 0; i < size; i++)
		if(code[i] == 10)
		{
			int j = i;
			while(code[--j] == ';');
			if(code[j] == 32)
				code [j] = ';';
		}

	//level.4 : clear all created ';'
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
		if(code[i] == 10 || code[i] == 32) //ASCII for newline or whitespace
			number_of_words++;
	return number_of_words;
}


//---------------------------------------------------------------------------------------//

void chartoword(char *code, unsigned long int size, char *words)
{

	int max_word_length = 10;
	int max_words_in_a_line = 4;

	//code [i] , words[p]
	unsigned long int i, p;
	//line number
	unsigned long int  j = 0;
	//word number in a line
	unsigned long int  k = 0;
	//char number in a word
	unsigned long int  l = 0;

	for(i = 0; i < size; i++)
	{
		if(code[i] == 10) //ASCII for newline or whitespace
		{
			k = 0;
			l = 0;
			j++;
			continue;
		}

		else if(code[i] == 32)
		{
			k++;
			l = 0;
		}

		p = j * max_words_in_a_line  * max_word_length + k * max_word_length + k;
		words[p] = code[i];
	}
}

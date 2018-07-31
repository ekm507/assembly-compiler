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
			while( ( code[++i] == 10 || code[i] == ';' || code[i] == ' ' ) && i < 
size)
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

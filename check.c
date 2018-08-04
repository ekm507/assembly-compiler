
#include "check.h"
#include "errors.h"
#include <stdlib.h>
#include <stdio.h>

#define error(a) send_error( ( a ), line, array )

int last_something = 0;
char reserved_names[][10] = {"ADD", "AND", "LDA", "STA", "BUN", "BSA", "LSZ", "CLA", "CLE", 
"CMA", "CME", "CIR", "CIL", "INC", "SPA", "SNA", "SZA", "SZE", "HLT", "INP", "OUT", "SKI", 
"SKO", "ION", "IOF", "ORG", "DEC", "HEX", "END"};

int number_of_reserved = 29;

int reserved(char word[10]);
int good_lable_name(char word[10]);
int wordlast(char word[10], char last);
int is_hex(char word[10]);
int is_dec(char word[10]);

void check(char array[5][10], unsigned long int line)
{
//	printf(" <%s - %s - %s - %s\n", array[1], array[2], array[3], array[4]);
	static char lable[100][5];
	static int last_lable = 0;
	int has_lable;
	if(wordlast(array[1], ',') )
	{
		array[1][strlen(array[1]) - 1] = '\0';
		has_lable = 1;
	}

	else
	{
		has_lable = 0;
		strcpy(array[4], array[3]);
		strcpy(array[3], array[2]);
		strcpy(array[2], array[1]);
		strcpy(array[1], "");
	}
//	printf(" >%s - %s - %s - %s\n", array[1], array[2], array[3], array[4]);
	//start
	if(has_lable)
	{
		if(!good_lable_name(array[1]) )
			error(2); //ERROR # 2
		else if(reserved(array[1]) )
			error(3); //ERROR # 3
		else
		{
			strcpy(lable[last_lable++], array[1]);
		}
	}
//	else if(array[4][0] != '\0')
//		error(1); // ERROR # 1

	printf(">%s-%s-%s-%s\n", array[1], array[2], array[3], array[4]);


	int array_4_length = strlen(array[4]);
	if(array_4_length == 1)
	{
		if(array[4][0] != 'i')
			error(4); // ERROR # 4
	}
	else if(array_4_length > 1)
		error(4); //ERROR # 4

	if(! reserved(array[2]) )
	{
		error(11); //ERROR # 11
	}
	else
	{
		if(strcmp(array[2], "END") && array[3][0] == '\0')
			error(13); //ERROR # 13
	}


	if(reserved(array[3] ) )
		error(12); //ERROR # 12

	if(!strcmp(array[2], "HEX") )
	{
		if(! is_hex(array[3] ) )
			error(5);//ERROR # 5
	}

	else if(!strcmp(array[2], "ORG") )
	{
		if(! is_hex(array[3] ) )
			error(6);//ERROR # 6
	}

	int decimality;
	decimality  = is_dec( array[3] );
	if(!strcmp(array[2], "DEC") )
	{
		if(! decimality )
			error(7);// ERROR # 7
		else if( decimality == 2)
			error(8);//ERROR # 8
	}

	else if(!strcmp(array[2], "END") )
	{
		if(array[3][0] != '\0' )
			error(9);//ERROR # 9
	}

	else if(array[2][0] == '\0')
		error(10);//ERROR # 10
}

//---------------------------------------------------------------------------

//check if last char of the word is what you want
int wordlast(char word[10], char last)
{
	if(strlen(word))
		if(word[ strlen(word) - 1] == last)
			return 1;
	return 0;
}

//---------------------------------------------------------------------------

int reserved(char word[10])
{
	for(int i = 0; i < number_of_reserved; i++)
		if( ! strcmp( word, reserved_names[i]) )
			return 1;
	return 0;
}

//---------------------------------------------------------------------------

int good_lable_name(char word[10])
{
	if(word[0] > '0' && word[0] < '9')
		return 0;
	if (strlen(word) > 4)
		return 0;
	return 1;
}

//---------------------------------------------------------------------------

int is_hex(char word[10])
{
	int length = strlen(word);
	if(length > 4 || length < 1)
		return 0;
	for(int i = 0; i < length; i++)
		if(word[i] >'F' || word[i] < '0')
			return 0;

	return 1;
}

//---------------------------------------------------------------------------

int is_dec(char word[10])
{
	int length = strlen(word);
	long int number = 0;
	int  k = 0;
	if(length < 1)
		return 0;
	if(word[0] == '-')
		k = 1;
	for(int i = k; i < length; i++)
		if(word[i] > '9' || word[i] < '0')
			return 0;
		else
			number = number * 10 + (word[i] - '0');
	if(number > 256 * 256)
		return 2;
	return 1;
}

//---------------------------------------------------------------------------

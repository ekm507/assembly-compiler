
#include "check.h"
#include "errors.h"
#include <stdlib.h>
#include <stdio.h>

#define error(a) send_error((a), line, array)

int last_something = 0;
char reserved_names[][10] = {"ADD", "AND", "LDA", "STA", "BUN", "BSA", "LSZ", "CLA", "CLE", 
"CMA", "CME", "CIR", "CIL", "INC", "SPA", "SNA", "SZA", "SZE", "HLT", "INP", "OUT", "SKI", 
"SKO", "ION", "IOF", "ORG", "DEC", "HEX", "END"};

int number_of_reserved = 29;

int reserved(char word[10]);
int good_lable_name(char word[10]);
int wordlast(char word[10], char last);

void check(char array[5][10], unsigned long int line)
{
	static char lable[100][5];
	static int last_lable = 0;
	int has_lable = 1;
	if(wordlast(array[1], ',') )
		array[1][strlen(array[1]) - 1] = '\0';

	else
	{
		has_lable = 0;
		strcpy(array[4], array[3]);
		strcpy(array[3], array[2]);
		strcpy(array[2], array[1]);
		strcpy(array[1], "");
	}

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


}

//---------------------------------------------------------------------------

//check if last char of the word is what you want
int wordlast(char word[10], char last)
{
	if(word[ strlen(word) - 1] == last)
		return 1;
	return 0;
}

//---------------------------------------------------------------------------

int reserved(char word[10])
{
	for(int i = 0; i < number_of_reserved; i++)
		if(strcmp(word, reserved_names[i]) )
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

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

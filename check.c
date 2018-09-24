#include "check.h"
#include "errors.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//macro for sending errors more easily
#define error(a) send_error( ( a ), line, array )

//reserved names will be stored here
char reserved_names[][10] = {"ADD", "AND", "LDA", "STA", "BUN", "BSA", "LSZ", "CLA", "CLE", 
"CMA", "CME", "CIR", "CIL", "INC", "SPA", "SNA", "SZA", "SZE", "HLT", "INP", "OUT", "SKI", 
"SKO", "ION", "IOF", "ORG", "DEC", "HEX", "END"};

//number of reserved names we have
int number_of_reserved = 29;

//check if a word is a reserved name
int reserved(char word[10]);

//check if a lable name is nice
int good_lable_name(char word[10]);

//check if last character of a word matches the character of 2nd argument
int wordlast(char word[10], char last);

//check if a word is a 16-bit hex number
int is_hex(char word[10]);

//check if a word is a 16-bit decimal number
int is_dec(char word[10]);

//check if a name is predefined
int predefined(char word[10]);

//defined lables will be stored here
static char lable[100][5];

//number of lables we have
static int last_lable = 0;

//check if there is any error in this line
void check(char array[5][10], unsigned long int line)
{
//	printf(" <%s - %s - %s - %s\n", array[1], array[2], array[3], array[4]);

	//if this line of the code has lable, this will be 1.
	int has_lable;

	//check if there is lable
	if(wordlast(array[1], ',') )
	{
		//delete the ',' character from lable name
		array[1][strlen(array[1]) - 1] = '\0';
		has_lable = 1;
	}

	else
	{
		//shift the array blocks due to check easier
		//array[i] : [0] = lable, [1] = instruction, [2] = operand. [3] = 'i' or ''
		has_lable = 0;
		strcpy(array[4], array[3]);
		strcpy(array[3], array[2]);
		strcpy(array[2], array[1]);
		strcpy(array[1], "");
	}
//	printf(" >%s - %s - %s - %s\n", array[1], array[2], array[3], array[4]);

	//start checking for errors

	if(has_lable)
	{
		//check if lable name is proper as a gentleman
		if(!good_lable_name(array[1]) )
			error(2); //ERROR # 2

		//check if lable name is not a reserved name
		else if(reserved(array[1]) )
			error(3); //ERROR # 3

		//store lable name in definitions array
		strcpy(lable[last_lable++], array[1]);

	}

	//for debugging you can use it
//	printf(">%s-%s-%s-%s\n", array[1], array[2], array[3], array[4]);

	//langth of 4th word will be stored here
	int array_4_length = strlen(array[4]);

	//check if 4th word is either 'i' or ''
	if(array_4_length == 1)
	{
		if(array[4][0] != 'i')
			error(4); // ERROR # 4
	}
	else if(array_4_length > 1)
		error(4); //ERROR # 4

	//check if there is an instruction in this line
	if(array[2][0] != '\0')
	{
		if(! reserved(array[2]) )
		{
			error(11); //ERROR # 11
		}

		else
		{
			//check if argumant comes after the instruvtion
			if(strcmp(array[2], "END") != 0 && array[3][0] == '\0')
				error(13); //ERROR # 13
			else
			{
				//check if the argument is predefined
				if(! predefined(array[3] ) )
					//but some instructions dont want a predefined one
					if( ( strcmp(array[2], "HEX" ) != 0 && strcmp(array[2], "DEC") != 0 && strcmp(array[2], "ORG") != 0) )
						error(14); //ERROR # 14
			}
		}
	}

	//check if word 3 is not a reserved word
	if(reserved(array[3] ) )
		error(12); //ERROR # 12

	//check if a 16-bit hex number comes after HEX instruction
	if(!strcmp(array[2], "HEX") )
	{
		if(! is_hex(array[3] ) )
			error(5);//ERROR # 5
	}

	//check if a 16-bit hex number comes after ORG instruction
	else if(!strcmp(array[2], "ORG") )
	{
		if(! is_hex(array[3] ) )
			error(6);//ERROR # 6
	}

	//is the argument a decimal(decimality = 1)? is it 16-bit(decimality = 2)?
	int decimality;

	//is it?
	decimality  = is_dec( array[3] );

	//check if a decimal comes after DEC instruction
	if(!strcmp(array[2], "DEC") )
	{
		if(! decimality )
			error(7);// ERROR # 7

		//check if that decimal is 16-bit
		else if( decimality == 2)
			error(8);//ERROR # 8
	}

	//check if there is any word after END instruction
	else if(!strcmp(array[2], "END") )
	{
		if(array[3][0] != '\0' )
			error(9);//ERROR # 9
	}

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
	if (strlen(word) > 3)
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
	if(word[0] == '-' || word[0] == '+')
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

int predefined(char word[10])
{
	for(int i = 0; i < last_lable; i++)
	{
		if(!strcmp(word, lable[i]) )
			return 1;
	}

	return 0;
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

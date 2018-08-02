
#include "check.h"
#include "errors.h"
#include <stdlib.h>
#include <stdio.h>

int last_something = 0;

//check if last char of the word is what you want
int wordlast(char *word, char last)
{
	int i;
	while(word[i++] != '\0');
	if(word[i - 2] == last)
		return 1;
	return 0;
}

void check(char array[5][10])
{
	int has_lable = 1;
	if(!wordlast(array[1], ',') )
	{
		if(!strcmp(array[4], "") )
		{
			send_error(1);// ERROR # 1
			return;
		}

		else
		{
			has_lable = 0;
			strcpy(array[4], array[3]);
			strcpy(array[3], array[2]);
			strcpy(array[2], array[1]);
		}
	}

	//start



}

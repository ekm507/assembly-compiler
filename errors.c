
#include "errors.h"
#include <stdio.h>

void send_error(int error_type, unsigned long int line, char array[5][10])
{
	printf("\nERROR #%d in line %lu :\n", error_type, line);

	for(int i = 1; i < 5; i++)
		printf("%s ", array[i]);
	printf("\n");


	switch(error_type)
	{
		case 0 :
			printf("more than 4 arguments.");
			break;
		case 1 :
			printf("too many arguments(array[1] == \"\" while array[4] != \"\").");
			break;
		case 2 :
			printf("not a nice lable name.");
			break;
		case 3 :
			printf("lable name can't be a reserved name.");
			break;
		case 4 :
			printf("last parameter should be either i or \"\"");
			break;
		default :
			printf("unknown error! call the idiot programmer.");
	}

	printf("\n");
}
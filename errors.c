
#include "errors.h"
#include <stdio.h>

void send_error(int error_type, unsigned long int line, char array[5][10])
{
	printf("\nERROR #%d in line %lu :\n", error_type, line);

	for(int i = 0; i < 4; i++)
		printf("%s ", array[i]);
	printf("\n");


	if(error_type == 0)
		printf("more than 4 arguments.");
	else if(error_type == 1)
		printf("too many arguments(array[1] == \"\" while array[4] != \"\").");
	else if(error_type == 2)
		printf("not a nice lable name.");
	else if(error_type == 3)
		printf("lable name can't be a reserved name.");
	else if(error_type == 2)
		printf("\n");
	printf("\n");
}

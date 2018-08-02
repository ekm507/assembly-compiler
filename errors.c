
#include "errors.h"
#include <stdio.h>

void send_error(int error_type, unsigned long int line)
{
	printf("#ERROR : %d in line %lu :\n ", error_type, line);


	if(error_type == 0)
		printf("more than 4 arguments.\n");
	else if(error_type == 1)
		printf("too many arguments(array[1] == "" while array[4] != "").");
	else if(error_type == 2)
		printf("not a nice lable name.\n");
	else if(error_type == 3)
		printf("lable name can't be a reserved name.\n");
	else if(error_type == 2)
		printf("\n");
	printf("\n");
}

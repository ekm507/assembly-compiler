
#include "errors.h"
#include <stdio.h>

void send_error(int error_type, unsigned long int line, char array[5][10])
{
	printf("\nERROR #%d in line %lu :\n", error_type, line);

	//print the line error has occured in
	if(array[1][0] != '\0')
	printf("%s, ", array[1]);
	for(int i = 2; i <= 4; i++)
		printf("%s ", array[i]);
	printf("\n");

	//print the proper error statement for the error code
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
		case 5 :
			printf("there should be a 16-bit hex number after HEX instruction");
			break;
		case 6 :
			printf("there should be a 16-bit HEX number after ORG instruction");
			break;
		case 7 :
			printf("there should be a 16-bit decimal number after DEC instruction");
			break;
		case 8 :
			printf("decimal number after DEC instruction should be 16-bit");
			break;
		case 9 :
			printf("there should be nothing after END instruction");
			break;
		case 10 :
			printf("missing instruction");
			break;
		case 11 :
			printf("there should be an instruction here");
			break;
		case 12 :
			printf("a reserved name can't come immediately after an instruction");
			break;
		case 13 :
			printf("missing operand");
			break;
		case 14 :
			printf("undefined operand");
			break;

		default :
			//foralien errors
			printf("unknown error! call the idiot programmer.");
	}

	printf("\n");
}

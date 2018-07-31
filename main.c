/* assembly compiler for "The 16-bit CPU"
*  main.c
*  the main file code.
*
* usage :
* ./a.out [asm code file name] -o [output file name]
*/


//TODO : check if file opens without any errors


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compiler.h"

int main(int argc, char**argv)
{

	//get filename to compile
	char filename[1000];
	if(argc < 2)
		scanf("%s", filename);
	else
		strcpy(filename, argv[1]);

	//get output filename
	char outputfilename[1000];
	strcpy(outputfilename, "output.bin");
	for(int i = 2; i < argc; i++)
		if(argv[i] == "-o")
		{
			strcpy(outputfilename, argv[i + 1]);
			break;
		}

	//open the code file
	FILE* codefile;
	codefile = fopen(filename, "r");

<<<<<<< HEAD
	//the code will be stored here
	char *code;

	unsigned long int size;
=======
	unsigned long int size;

	fseek(codefile, 0, SEEK_END); // seek to end of file
	size = ftell(codefile); // get current file pointer
	fseek(codefile, 0, SEEK_SET); // seek back to beginning of file

	char *code;
	code = malloc(size * sizeof(char));
>>>>>>> dynamic-code-size
	unsigned long int i = 0;


	while(!feof(codefile))
		code[++i] = fgetc(codefile);
	fclose(codefile);

	//compile the code
	int status = -1;
	status = compile(code, i);

	printf("\n--------------------------------------\n");

	//check if it was successful
	if(status)
		printf("COMPILATION FAILED!!!!\n");
	else
		printf("succfully compiled into : %s\n", outputfilename);

	return 0;
}

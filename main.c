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
#include "process.h"

int main(int argc, char**argv)
{

	printf("\n-------------------------------------PRECOMPILE-\n");


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
		if(strcmp(argv[i], "-o"))
		{
			strcpy(outputfilename, argv[i + 1]);
			break;
		}

	//open the code file
	FILE* codefile;
	codefile = fopen(filename, "r");

	unsigned long int size;

	//get file size
	fseek(codefile, 0, SEEK_END); // seek to end of file
	size = ftell(codefile); // get current file pointer
	//open and close the file in order to seek to the begining of the file
	fclose(codefile);
	codefile = fopen(filename, "r");

	//the code will be stored here
	char *code;
	code = malloc(size * sizeof(char));

	unsigned long int i = 0;

	//load the code file into memory
	while(!feof(codefile))
		code[++i] = fgetc(codefile);

	//close the code file
	fclose(codefile);

	//file to output the machine code
	FILE *outputfile;
	outputfile = fopen(outputfilename, "w");


	//process and compile the code
	int status = -1;
	status = process(code, i, outputfile);


	//last things
	printf("\n--------------------------------------\n");

	//close the output file
	fclose(outputfile);

	//check if it was successful
	if(status)
		printf("COMPILATION FAILED!!!!\n");
	else
		printf("succfully compiled into : %s\n", outputfilename);

	return 0;
}

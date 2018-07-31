/* assembly compiler for "The 16-bit CPU"
*  main.c
*  the main file code.
*/
//TODO : check if file opens without any errors


#include <stdio.h>
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

	char outputfilename[1000];
	if(argc < 3)
		strcpy(outputfilename, "output.bin");
	else
		strcpy(outputfilename,  argv[2]);

	//load file into the memory
	FILE* codefile;
	codefile = fopen(filename, "r");
	char code[10000];
	unsigned long int i = 0;
	while(!feof(codefile))
		code[++i] = fgetc(codefile);
	fclose(codefile);
	int status = -1;
	status = compile(code, i);
	//check if it was successful
	if(status)
		printf("COMPILATION FAILED!!!!\n");
	else
		printf("succfully compiled into : %s\n", outputfilename);

	return 0;
}

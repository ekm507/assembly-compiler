#include "read_write.h"
#include <stdio.h>

unsigned long int getfilesize(FILE *file)
{
	//seek to end of the file
	fseek(file, 0, SEEK_END);
	//get current file pointer
	long int size = ftell(file);
	//seek back to begining of the file
	fseek(file, 0, SEEK_SET);

	return size;
}

int read(char *filename, char* sourcecode)
{
	FILE *codefile;
        codefile = fopen(filename, "r");
        if(codefile == NULL)
        {
                perror("error openinig file\n");
		return -1;
	}

	//get codefile size
	unsigned long int size = 
getfilesize(codefile);
	//allocate memory for sourcecode
	sourcecode = malloc(size * sizeof(char));

	//upload the file into the memory
	long int i = 0;
	for(i = 0; i < size; i++)
		sourcecode[i] = fgetc(codefile);

	//close the file
	fclose(codefile);

	//returns 0 if there are no errors.
	return 0;
}

/* Assembly compiler for "The 16-bit CPU"
*  read_write.h
*  includeing:
	read
	write
	getfilesize
*/

#ifndef READ_WRITE_H
#define READ_WRITE_H

#include <stdio.h>

int read(char *filename, char *sourcecode);
int write(char *filename, char *hexcode);
unsigned long int getfilesize(FILE *file);

#endif // READ_WRITE_H

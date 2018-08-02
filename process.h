/* Assembly compiler for "The 16-bit CPU"
*  process.h
*  includeing:
	process function
*/

#ifndef PROCESS_H
#define PROCESS_H

#include "errors.h"
#include <stdio.h>
#include <stdlib.h>

int process(char* code, unsigned long int size, FILE *outputfile);

#endif //PROCESS_H

/* Assembly compiler for "The 16-bit CPU"
*  process.h
*  includeing:
	process function
*/

#ifndef PROCESS_H
#define PROCESS_H

int process(char* code, unsigned long int size, FILE *outputfile);

#endif //PROCESS_H

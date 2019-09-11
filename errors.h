
#ifndef ERRORS_H
#define ERRORS_H

#include <stdio.h>

//prints an error string, based on error number. (error_type)
void send_error(int error_type, unsigned long int line, char array[5][10]);

#endif//ERRORS_H

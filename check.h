
#ifndef CHECK_H
#define CHECK_H

#include "errors.h"
#include <stdlib.h>
#include <stdio.h>

//checkes a code to see if there are errors.
//prints errors using send-error function defined in errors.h. 
void check(char array[5][10], unsigned long int line);

#endif//CHECK_H

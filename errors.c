
#include "errors.h"
#include <stdio.h>

void send_error(int errortype)
{
	printf("#ERROR : %d\n", errortype);
}

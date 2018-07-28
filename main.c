/* assembly compiler for "The 16-bit CPU"
*  main.c
*  the main file code.
*/
//TODO : check if file opens without any errors


#include <stdio.h>
#include <compiler.h>

int main(int argc, char**argv)
{
	//get filename to compile
	char filename[1000];
	if(argc < 2)
		scanf("%s", filename);
	else
		filename = argv[1];

	char outputfilename[1000];
	if(argc < 3)
		outputfilename = "output.bin"
	else
		outputfilename = argv[2];
	//call the compile function
	int laststatus = compile(filename, outputfiolename);
	if(laststatus)
		printf("COMPILATION FAILED!!!!\n");
	else
		printf("succfully compiled into : %s", outputfilename);

	return 0;
}

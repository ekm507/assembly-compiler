// space = 32
// newline = 10
#include <stdio.h>

int main()
{
	FILE *fp;
	fp = fopen("code.asm", "r");
	if(fp == NULL)
	{
		perror("error opening file\n");
		return -1;
	}
	int c;
	int q = 0;
	do
	{
		c = fgetc(fp);
		if(feof(fp))
			break;
		printf("%c", c);
		if(c == 10 || c == ';')
		{
			printf("\ncommand ");
			q = 0;
		}
		if(c == 32)
		{
			q++;
			if(q == 1)
				printf(" with arguments: ");
			else
				printf(" and ");
		}
	}while(1);
	fclose(fp);
	return 0;
}

#include <stdio.h>

void main()
{
	FILE* fp = fopen("./data.txt", "r");

	int c ;

	while (1) 
	{
		c = getc(fp); 
		if (c == EOF)
			break;

		putc(c, stdout);
	}

	printf("EOF: 0x%x\n", EOF);
}



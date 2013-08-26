#include <stdio.h>

void main(void)
{
/*
	char c;
	char x;

	for (x = 'F'; x >= 'A'; x--)
	{
		for (c = 'F'; c >= x; c--)
		{
			printf("%c", c);
		}
		printf("\n");
	}
*/

	int i = 0;
	int j = 0;

	for (i = 1; i <= 9; i++)
	{
		//for (j = 1; j <= 9; j++)
		for (j = 1; j <= i; j++)
		{
			printf("%2d ", i*j);
		}

		printf("\n");
	}


}






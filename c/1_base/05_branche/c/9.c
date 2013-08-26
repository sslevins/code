#include <stdio.h>

void main(void)
{
	int i = 10;

	while (1)
	{
		printf("hello ");
		i--;
		if (i == 5)
		{
			//break;
			continue;
		}
		printf("world\n");
	}

	printf("good ");
	printf("bye \n");

}


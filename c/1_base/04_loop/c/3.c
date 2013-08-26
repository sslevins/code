#include <stdio.h>

void main(void)
{
	int i = 0;

	while (i > 0)
	{
		printf("hello\n");
	}

	printf("over\n");

	do
	{
		printf("hello\n");
	} 
	while (i > 0);
	printf("over\n");

}



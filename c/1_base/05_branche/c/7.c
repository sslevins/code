#include <stdio.h>

void main(void)
{
	int i = -1;

	//if (i++ && i++ && i++ && i++ && i++)
	if (i++ || i++ || i++ || i++ || i++)
	{
		printf("here\n");
	}
	else
	{
		printf("there\n");
	}

	printf("%d\n", i);
}







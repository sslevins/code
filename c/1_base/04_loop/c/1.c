#include <stdio.h>

void main()
{
	int i = 10;

	while (--i > 0)
	{
		printf("%d hello\n", i);
		// i--;
	}

	printf("over\n");
}

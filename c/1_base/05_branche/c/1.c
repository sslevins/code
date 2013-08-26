#include <stdio.h>

void main(void)
{
	int i = 10;
	int j = 5;

	while (i > 0)
	{
		if (j) 
		{
			printf("%d: true\n", j);
		} 
		else 
		{
			printf("%d: false\n", j);
		}

		i--;
		j--;
	}

}



#include <stdio.h>

void main(void)
{
	while (1)
	{
		while (1)
		{
			printf("hello world\n");
			goto here;
		}
		printf("good bye\n");
	}

here:
	printf("over\n");
	goto here;
	

}






#include <stdio.h>

int test(int *, int);

int main(void)
{
	int i = 5;

	printf("%d %d %d %d\n", 
		--i, ++i, i--, i++);
	//5, 6, 6, 5

	// printf("%d %d\n", test(&i, 1), test(&i, 2));

	return 0;
}

int test(int * p, int i)
{
	switch (i)
	{
		case 1:
			printf("1th \n");
			--(*p);
			break;
		case 2:
			printf("2th \n");
			++(*p);
			break;
	}

	return *p;
}






#include <stdio.h>

void do_it(void)
{
	printf("hello world\n");
}

int sum(int i, int j)
{
	return i+j;
}

void main()
{

	void (*p)(void) = NULL; 
	p = do_it;

	int (*q)(int, int) = NULL;
	q = sum;

	p();
	int ret = q(1, 2);
	printf("%d\n", ret);
}




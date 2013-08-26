#include <stdio.h>

int* do_it(void)
{
	int i = 100;

	return &i;
}

void main()
{
	int* p = do_it();

	printf("%d\n", *p);
}

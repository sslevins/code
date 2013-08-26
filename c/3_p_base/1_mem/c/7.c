#include <stdio.h>
#include <stdlib.h>

int* do_it(void)
{
	int* p;

	p = (int *)malloc(sizeof(int));

	*p = 100;

	return p;
}

void main()
{
	int* p; 

	p = do_it();

	printf("%d\n", *p);

	free(p);
}



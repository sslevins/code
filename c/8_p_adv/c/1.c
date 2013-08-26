#include <stdio.h>

void main()
{
	int i; 
	int* p;
	int ** q;

	i = 100;
	p = &i; 	// int *  = &(int)
	q = &p;		// int ** = &(int*)

	printf("%x %x %x\n", i, *p, **q);
	printf("%x %x\n", p, *q);
	printf("%x\n", q);

	q
	*q
	**q
}




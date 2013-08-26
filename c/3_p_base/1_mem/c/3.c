#include <stdio.h>

void main()
{
	int i = 10;

	int* p = &i;
	//printf("%p\n", p);
	printf("%d\n", *p);

	i++; 	printf("%d\n", *p);
	i++; 	printf("%d\n", *p);
	i++; 	printf("%d\n", *p);

//	p = 100;
	*p = 100;

	printf("%d\n", i);

}






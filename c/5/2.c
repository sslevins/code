#include <stdio.h>

void main()
{
	int arr[5] = {1, 2, 3, 4, 5};

	int (*p)[] = &arr;

	// printf("%p\n", p);


	printf("%p\n", arr);
	printf("%p\n", &arr);

	printf("%p\n", arr+1);
	printf("%p\n", &arr+1);
}








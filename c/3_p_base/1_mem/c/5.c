#include <stdio.h>

void half(int* i)
{
	*i = *i/2;
}

void main()
{
	int i = 10;
	half(&i);
	printf("%d\n", i);














	int j = 100;
	printf("%d, %d\n", i, j);	// 10, 100

	swap(&i, &j);
	printf("%d, %d\n", i, j);	// 100, 10









}







void swap(int* i, int* j)
{
	int temp = 0;
	temp = *i;
	*i = *j;
	*j = temp;
}


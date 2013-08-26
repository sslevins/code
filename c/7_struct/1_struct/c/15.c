#include <stdio.h>

typedef enum 
{
	red,
	blue,
	white = 100,
	black,
} COLOR;

void do_it(int i, int j, COLOR cor)
{
	printf("%d, %d, %d\n", i, j, cor);
}

void main()
{	
	do_it(10, 100, black);
}




#include <stdio.h>

struct yy
{
	char c;
	int i;
	float f;
};

void main()
{
	struct yy arr[4];	
	
	printf("%d\n", sizeof(arr));

	arr[0].c = 'a';
	arr[0].i = 100;
	arr[0].f = 3.14;

	arr[1].c = 'b';
	arr[1].i = 1000;
	arr[1].f = 4.14;

	arr[2].c = 'c';
	arr[2].i = 10000;
	arr[2].f = 5.14;

	arr[3].c = 'd';
	arr[3].i = 100000;
	arr[3].f = 6.14;
}


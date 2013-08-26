#include <stdio.h>

struct yy
{
	char buf[10];
	int arr[8];
};

void main()
{
	printf("%d\n", sizeof(struct yy));
}

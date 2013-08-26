#include <stdio.h>

void main(void)
{
	int arr[10] = {0};

	int len = sizeof(arr)/sizeof(arr[0]);

	int i = 0;
	for (i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}

	printf("\n");

}






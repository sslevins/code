#include <stdio.h>

void main()
{
	int arr[2][3] = {{1, 2, 3}, {4, 5, 6}};

	printf("%d ", arr[0][0]);
	printf("%d ", arr[0][1]);
	printf("%d ", arr[0][2]);
	printf("\n");
	printf("%d ", arr[1][0]);
	printf("%d ", arr[1][1]);
	printf("%d ", arr[1][2]);
	printf("\n");

	printf("----------------\n");

	printf("%d ", arr[0][0]);
	printf("%d ", arr[0][1]);
	printf("%d ", arr[0][2]);
	printf("%d ", arr[0][3]);
	printf("%d ", arr[0][4]);
	printf("%d ", arr[0][5]);

	printf("\n");
}

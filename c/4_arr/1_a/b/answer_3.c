#include <stdio.h>

void d_value(int arr[][5], int k)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < k; i++)
		for (j = 0; j < 5; j++)
			arr[i][j] = 2*arr[i][j];
}

void main()
{
	int arr[3][5] = {
						{1, 2, 3, 4, 5}, 
						{6, 7, 8, 9, 10}, 
						{11, 12, 13, 14, 15}
					}; 
	d_value(arr, 3);

	int i = 0;
	int j = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
}




#include <stdio.h>

void main()
{
	int arr[2][3] = {{1, 2, 3}, {4, 5, 6}};

	int i = 0;
	int j = 0;

	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}	

}


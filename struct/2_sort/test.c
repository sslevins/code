#include <stdio.h>

#define LEN 11

int num = 0;

void print_arr(int arr[])
{
	int i = 0;
	printf("%d: ", num++);
	for (; i < LEN; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void main()
{
	int arr[LEN] = {7, 4, 18, 8, 20, 3, 6, 2, 5, 11, 10};

	int pivot = arr[6];	// 6

	int l = 0;
	int r = LEN-1;

	for (; l < r && arr[l] < pivot; l++)	
		;
	
	for (; l < r && arr[r] >= pivot; r--)
		;
	
	arr[6] = arr[l];

	while (l < r)
	{
		arr[l] = arr[r];
		for (; l < r && arr[l] < pivot; l++)	
			;

		arr[r] = arr[l];
		for (; l < r && arr[r] >= pivot; r--)
			;
	}

	arr[l] = pivot;

	print_arr(arr);

}





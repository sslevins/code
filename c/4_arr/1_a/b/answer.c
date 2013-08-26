#include <stdio.h>

int max(int arr[], int len)
{
	int max = 0;
	int i = 0;

	for (i = 0; i < len; i++)
	{
		if (arr[i] >= max)
		{
			max = arr[i];
		}
	}

	return max;
}

double sub(double arr[], int len)
{
	double min = arr[0];
	double max = arr[0];
	int i = 0;

	for (i = 1; i < len; i++)
	{
		if (arr[i] >= max)
		{
			max = arr[i];
		} 
		else if (arr[i] <= min)
		{
			min = arr[i];
		} 
		else
		{
			;
		}
	}
	//printf("debug: %lf %lf\n", max, min);

	return max-min;
}

void main()
{
	int i = 0;
	double j = 0.0;

	int arr_1[] = {3, 4, 6, 8, 29, 59, 43, 72};
	i = max(arr_1, sizeof(arr_1)/sizeof(arr_1[0]));
	printf("%d\n", i);


	double arr_2[] = {3.2, 5.6, 4.1, 7.2, 1.8, 0.9, 10.4, 9.1, 2.3};
	j = sub(arr_2, sizeof(arr_2)/sizeof(arr_2[0]));
	printf("%lf\n", j);
}




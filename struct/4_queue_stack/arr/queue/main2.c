#include <stdio.h>

#define LEN 5

int in_pos = 0;
int out_pos = 0;

void in_queue(int _arr[], int _data)
{
	if ((in_pos+1)%LEN == out_pos)
	{
		printf("queue is full\n");
		return ;
	}

	_arr[in_pos] = _data;
	in_pos = (in_pos + 1) % LEN;
}

int out_queue(int _arr[])
{
	if (in_pos == out_pos)
	{
		printf("queue is empty\n");
		return ;
	}

	int ret = _arr[out_pos];
	_arr[out_pos] = 0; 
	out_pos = (out_pos + 1) % LEN;

	return ret;
}

void queue_for_each(int _arr[])
{
	int i = 0;

	for (i = out_pos; 
			i != in_pos; 
			i = (i + 1) % LEN)
	{
		printf("%d ", _arr[i]);
	}
	printf("\n");
}

void main()
{
	int arr[LEN] = {0};

	in_queue(arr, 9);
	in_queue(arr, 5);
	in_queue(arr, 2);
	in_queue(arr, 7);
	queue_for_each(arr);

	out_queue(arr);
	out_queue(arr);
	queue_for_each(arr);

	in_queue(arr, 3);
	queue_for_each(arr);

}


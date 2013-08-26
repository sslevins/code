#include <stdio.h>

#define LEN 5

int in_pos = 0;

void in_queue(int _arr[], int _data)
{
	if (in_pos == LEN)
	{
		printf("queue is full\n");
		return ;
	}

	_arr[in_pos] = _data;
	in_pos++;
}

int out_queue(int _arr[])
{
	if (in_pos == 0)
	{
		printf("queue is empty\n");
		return 0;
	}

	int ret = _arr[0];

	int i = 0;
	for (i = 1; i < in_pos; i++)
		_arr[i-1] = _arr[i];
	
	_arr[in_pos] = 0;
	in_pos--;

	return ret;
}

void queue_for_each(int _arr[])
{
	int i = 0;
	for (i = 0; i < in_pos; i++)
		printf("%d ", _arr[i]);
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


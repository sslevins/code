#include <stdio.h>

#define LEN 10

int pos = 0;

void push(int _arr[], int _data)
{
	if (pos == LEN)
	{
		printf("stack is full\n");
		return ;
	}

	_arr[pos] = _data;
	pos++;
}

int pop(int _arr[])
{
	if (pos == 0)
	{
		printf("stack is empty\n");
		return 0;
	}

	pos--;
	int ret = _arr[pos];
	_arr[pos] = 0;

	return ret;
}

void stack_for_each(int _arr[])
{
	int i = 0;
	for (i = pos-1; i >= 0; i--)
		printf("%d ", _arr[i]);
	
	printf("\n");
}

void main()
{
	int arr[LEN] = {0};
	push(arr, 1);
	push(arr, 2);
	push(arr, 3);
	push(arr, 4);
	stack_for_each(arr);

	pop(arr);
	pop(arr);
	stack_for_each(arr);

	push(arr, 5);
	push(arr, 6);
	stack_for_each(arr);

	pop(arr);
	pop(arr);
	pop(arr);
	stack_for_each(arr);

	push(arr, 7);
	push(arr, 8);
	stack_for_each(arr);


}






#include <stdio.h>

// void do_it(int arr[])
void do_it(int* arr)
{
	printf("%d\n", sizeof(arr));

	printf("%d, %d\n", arr[0], *(arr+0));
	printf("%d, %d\n", arr[1], *(arr+1));
	printf("%d, %d\n", arr[2], *(arr+2));
	printf("%d, %d\n", arr[3], *(arr+3));
	printf("%d, %d\n", arr[4], *(arr+4));

}


void main()
{
	int arr[] = {1, 2, 3, 4, 5};

	do_it(arr);
}

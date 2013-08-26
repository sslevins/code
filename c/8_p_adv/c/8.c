#include <stdio.h>

void hello(void)
{
	printf("hello\n");
}

void world(void)
{
	printf("world\n");
}

void goodbye()
{
	printf("goodbye\n");
}

void main()
{
	//int arr[3];
	//int* arr[3];

	void (*arr[3])(void);
	printf("%d\n", sizeof(arr));

	arr[0] = hello;
	arr[1] = world;
	arr[2] = goodbye;

	arr[1](); // world();

}




#include <stdio.h>

void main(void)
{
	char arr[10];

	int len = sizeof(arr)/ sizeof(arr[0]);
	int i = 0;
	char input = 0;

	for (i=0; i<len; i++)
	{
		printf("please input a char: ");
		scanf("%c", &input);
		getchar();
		arr[i] = input;
	}

	//for (i=len-1; i>=0; i--)
	for (i=0; i<len; i++)
	{
		printf("%c ", arr[len-1-i]-32);
	}
	printf("\n");
	
}



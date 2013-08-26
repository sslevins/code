#include <stdio.h>

void main()
{
	//char arr[] = {'h', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd', '\0'};
	//printf("%d\n", sizeof(arr));
	
	char arr[] = "hello world";

	
	printf("%s\n", arr);

	arr[4] = '\0';

	printf("%s\n", arr);
}

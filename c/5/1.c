#include <stdio.h>

int main()
{
	char* arr[] = {"hello", "world", "good", "bye"};

	printf("%d\n", sizeof(arr));

	printf("%s\n", *(arr+1));

}

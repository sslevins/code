#include <stdio.h>

void main()
{
	char arr[] = "please input a string: ";
	char input[] = {0};


	printf("%s", arr);
	scanf("%s", input);

	printf("you just input: %s\n", input);
}

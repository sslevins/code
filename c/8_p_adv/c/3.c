#include <stdio.h>

void do_it(char** x)
{
	(*x)++;
	printf("%s\n", *x);	
}


int main()
{

	char* arr[3] = {"hello", "world", "goodbye"};

	do_it(arr);

	return 0;
}


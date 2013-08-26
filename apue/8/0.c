#include <stdio.h>

union X {
	int i;
	char arr[4];
};

int main()
{
	union X hello;
	hello.i = 0x00000001;

	if (arr[0] == 0)
		printf("");
	else
		printf("");
	
	return 0;
}


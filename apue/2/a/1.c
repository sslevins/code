#include <stdio.h>
#include <stdlib.h>

int main()
{
	printf("goto exec pwd\n");

	int ret = system("init 0");

	printf("done!\n");
}




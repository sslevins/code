#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	char arr[128];
	memset(arr, 0, 128);
	arr[0] = 'x';

	int pid = fork();
	if (pid == -1)
		exit(1);
	else if (pid == 0)
	{
		printf("%c\n", arr[0]);
	}
	else
	{
		wait(NULL);
		printf("%c\n", arr[0]);
	}
}


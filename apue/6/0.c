#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int i = 0;

int main()
{
	int pid = 0;

	pid = fork();
	if (pid == -1)
		exit(1);
	else if (pid == 0)
	{
		i++;
		exit(0);
	}

	i--;

	printf("%d\n", i);

	return 0;
}


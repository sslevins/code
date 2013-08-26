#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
	int pid = fork();

	if (pid == -1)
	{
		exit(1);
	}
	else if (pid == 0)
	{
		printf("%d, %d\n", getpid(), getppid());
		sleep(3);
		printf("%d, %d\n", getpid(), getppid());
	}
	else
	{
		sleep(1);
		exit(0);
	}

	return 0;
}


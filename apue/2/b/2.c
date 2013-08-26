#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
	int pid = 0;

	pid = fork();
	if (pid == -1)
	{
		exit(1);
	}
	else if (pid == 0)
	{
		printf("i am child.\n");
		printf("%d, %d, %d\n", getpid(), getpgid(0), getsid(0));

		setsid();

		printf("%d, %d, %d\n", getpid(), getpgid(0), getsid(0));

	}
	else
	{
		wait(NULL);
		printf("---------------\n");
		printf("i am parent.\n");
	}


	return 0;
}

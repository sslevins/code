#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
	int i = 100;

	int pid = fork();
	if (pid == -1)
		exit(1);
	else if (pid == 0) {
		i++;
		exit(0);
	}

	wait(NULL);
	printf("%d\n", i);
}


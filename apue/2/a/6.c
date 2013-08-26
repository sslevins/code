#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	char * argv[] = {"b.out", 0};

	int pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(1);
	} 
	else if (pid == 0)
	{
		sleep(2);
		execv("./b.out", argv);
		perror("execvp");
		exit(2);
	}

	int status = 0;
	wait(&status);
	if(WIFEXITED(status)) 
	{ 
		printf("exited, status=%d\n", 
			WEXITSTATUS(status));
	}

	printf("hello world!\n");

	return 0;
}



#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	char * argv[] = {"ls", "-l", "-a", 0};

	int pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(1);
	} 
	else if (pid == 0)
	{
		execvp("ls", argv);
		perror("execvp");
		exit(2);
	}

	printf("hello world!\n");

	return 0;
}




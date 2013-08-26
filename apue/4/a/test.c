#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>

int main()
{
	int ret = 0;
	int fd[2];	
	int pid = 0;

	ret = pipe(fd);
	if (ret == -1)
	{
		perror("pipe");
		exit(1);
	}

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(1);
	}
	else if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], 1);

		// execlp("pwd", "pwd", NULL);
		execlp("ls", "ls", "-a", "-l", NULL);
		perror("execlp");
	}

	close(fd[1]);
	char buf[128];
	memset(buf, 0, 128);
	wait(NULL);
	int nchar = 0;

	while ((nchar = read(fd[0], buf, 128)) > 0)
		printf("%s", buf);

}











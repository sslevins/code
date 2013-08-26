#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

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
		long flag = fcntl(1, F_GETFL);
		fcntl(1, F_SETFL, flag|O_NONBLOCK);

		// execlp("pwd", "pwd", NULL);
		execlp("ls", "ls", "-a", "-l", NULL);
		close(fd[1]);
		perror("execlp");
	}

	sleep(1);
	close(fd[1]);
	char buf[128];
	memset(buf, 0, 128);
	int nchar = 0;

	long flag = fcntl(fd[0], F_GETFL);
	fcntl(fd[0], F_SETFL, flag|O_NONBLOCK);
	while ((nchar = read(fd[0], buf, 128)) > 0)
	{
		buf[nchar] = '\0';
		printf("%s", buf);
	}
	printf("\n");

	close(fd[0]);

}











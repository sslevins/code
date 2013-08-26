#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define oops(m, x) {perror(m); exit(x);}

int main()
{
	int fd = open("./temp.txt", O_RDWR);
	if (fd == -1)
		oops("open", 1);
	
	int pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(2);
	}
	else if (pid == 0)
		printf("I am child\n");
	else
		printf("I am parent\n");
	
	return 0;
}







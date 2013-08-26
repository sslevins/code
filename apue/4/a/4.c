#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define STR "hello world!"
#define oops(m, x) {perror(m); exit(x);}

int main()
{
	int fd[2];
	pipe(fd);
	
	int pid = fork();
	if (pid == -1) {
		perror("fork");
		exit(2);
	} 
	else if (pid == 0) {
		close(fd[0]);	
		write(fd[1], STR, sizeof(STR));
		exit(3);
	}

	char buf[128];
	memset(buf, 0, 128);

	sleep(1);
	close(fd[1]);
	read(fd[0], buf, 128);

	printf("parent: %s\n", buf);
	
	return 0;
}



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
		close(fd[1]);

		exit(3);
	}

	char buf[128];
	memset(buf, 0, 128);

	sleep(3);

	close(fd[1]);

	int ret = read(fd[0], buf, 128);
	if (ret == -1)
		perror("parent read");

	printf("parent: %s\n", buf);
	
	return 0;
}



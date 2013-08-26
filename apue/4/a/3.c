#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define oops(m, x) {perror(m); exit(x);}

int main()
{
	int fd = open("./hello", O_RDWR);
	if (fd == -1)
		oops("open", 1);
	
	int pid = fork();
	if (pid == -1) {
		perror("fork");
		exit(2);
	} 
	else if (pid == 0) {
		lseek(fd, 0, SEEK_END);
		write(fd, "goodbye\n", 9);
		exit(3);
	}

	wait(NULL);
	lseek(fd, 0, SEEK_END);
	write(fd, "say hi\n", 8);

	return 0;
}



#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

#define STR "hello world!\n"

int main()
{
	int pid = fork();
	if (pid == -1)
		exit(1);
	else if (pid > 0)
		exit(0);
	
	setsid();
	chdir("/");
	close(0);
	close(1);
	close(2);

	while (1)
	{
		sleep(1);
		int fd = open("/tmp/daemon.log", 
						O_RDWR|O_APPEND|O_CREAT, 
						0600);
		if (fd == -1)
			exit(1);

		write(fd, STR, strlen(STR)+1);
	}

	return 0;
}



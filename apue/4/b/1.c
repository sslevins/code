#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
	if( access("./fifo", F_OK) )
		mkfifo("./fifo", 0600);
	
	int pid = 0;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(1);
	}
	else if (pid == 0)
	{
		int fd = open("./fifo", O_WRONLY);
		int i = 10000;
		while (i--)
			write(fd, "x ", 2);

		write(fd, "!", 1);

		close(fd);
		exit(0);
	}

	sleep(1);
	char buf[128];
	memset(buf, 0, 128);

	int fd = open("./fifo", O_RDONLY);

	int nchar = 0;
	while ( (nchar = read(fd, buf, 128)) > 0 )
	{
		buf[nchar] = '\0';
		printf("%s", buf);
		fflush(stdout);
	}
	printf("\n");

	close(fd);
	
	return 0;
}






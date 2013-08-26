#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define oops(m, x) {perror(m); exit(x);}


int main()
{
	int fd[2];

	int ret = pipe(fd);
	if (ret == -1)
		oops("pipe", 1);
	
	char buf[128];
	memset(buf, 0, 128);

	write(fd[1], "hello world!", 13);

	read(fd[0], buf, 128);

	printf("%s\n", buf);

	return 0;
}




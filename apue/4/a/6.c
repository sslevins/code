#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define STR "hello world!\n"

int main()
{
	// close(1);

	int fd = open("./hello", O_RDWR);

	dup2(fd, 1);
	close(fd);

	printf("hello world!\n");

	return 0;
}




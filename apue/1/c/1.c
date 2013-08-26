#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>

int main()
{
	int fd = open("/dev/pts/1", O_RDWR);
	if (fd == -1)
	{
		perror("open");
		exit(1);
	}

	int ret = write(fd, "hello world!", 13);
	if (ret != 13)
	{
		perror("write");
		exit(2);
	}

	return 0;

}

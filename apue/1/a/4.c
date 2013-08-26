#include <stdio.h>		// printf()
#include <stdlib.h>		// exit()
#include <unistd.h>		// read() 	write()
#include <fcntl.h>		// open()
#include <sys/stat.h>	// S_IRWXU
#include <sys/types.h>	// ssize_t size_t
#include <string.h>		// memset()

int main()
{
	int ret = 0;

	int fd = open("a.txt", O_RDWR | O_APPEND);
	if (fd == -1)
	{
		printf("open error!\n");
		exit(1);
	}

	ret = lseek(fd, 0, SEEK_END);
	if (ret == -1)
	{
		printf("lseek error!\n");
		exit(2);
	}

	char * str = "goodbye!";
	ret = write(fd, str, strlen(str));
	if (ret == -1)
	{
		printf("write error!\n");
		exit(3);
	}

	ret = lseek(fd, 0, SEEK_SET);
	if (ret == -1)
	{
		printf("lseek error!\n");
		exit(4);
	}

	char buf[128];
	memset(buf, 0, 128);
	ret = read(fd, buf, 128);
	if (ret == -1)
	{
		printf("read error!\n");
		exit(5);
	}

	printf("%s\n", buf);

	return 0;
}







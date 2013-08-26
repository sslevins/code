#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

#define oops(x, num) {perror(x);exit(num);}

int main()
{
	char buf[128];
	int fd = 0;

	long flag = fcntl(fd, F_GETFL);

	fcntl(fd, F_SETFL, flag|O_NONBLOCK);

	int ret = read(fd, buf, 128);
	printf("%d\n", errno);
	if (ret == -1)
		oops("read", 1);

	printf("over\n");

	return 0;
}




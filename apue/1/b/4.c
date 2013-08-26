#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#define oops(x, num) { perror(x); exit(num); }

int main()
{
	int fd = open("./xxx", O_RDONLY);
	if (fd == -1)
		oops("open", 1);

	return 0;
}

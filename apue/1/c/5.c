#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

#define oops(x, m) {perror(x); exit(m);}

int main()
{
	int fd = open("temp.txt", O_RDWR);
	if (fd == -1)
		oops("open", 1);
	
	char buf[4096];
	memset(buf, 0, 4096);

	char * addr = mmap(buf, 4096, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);

	printf("%s", addr);
	sprintf(addr, "goodbye", 8);

	return 0;
}





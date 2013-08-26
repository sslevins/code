#include <stdio.h>

void main()
{
	char buf[1024];

	setvbuf(stdout, buf, _IOFBF, 1);
	// _IONBF, _IOLBF, _IOFBF

	while (1)
	{
		printf(".");
		//fflush(stdout);
		sleep(1);
	}
}

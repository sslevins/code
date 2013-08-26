#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void do_it(int num)
{
	printf("%d\n", num);
}

int main()
{
	signal(SIGALRM, do_it);

	while (1)
	{
		alarm(1);
		pause();
		printf(".");
		fflush(stdout);
	}

	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void int_handler(int num)
{
	printf("in int_handler\n");
	sleep(3);
	printf("out int_handler\n");
}

void quit_handler(int num)
{
	printf("in quit_handler\n");
	printf("out quit_handler\n");
}

int main()
{
	signal(SIGINT, int_handler); 	// ctrl+c
	signal(SIGQUIT, quit_handler);	// ctrl+\

	while (1)
	{
		sleep(1);
	}

	return 0;
}





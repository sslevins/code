#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void int_handler(int num)
{
	printf("in int_handler\n");
	sleep(3);
	printf("out int_handler\n");
}

int main()
{
	struct sigaction act;

	sigemptyset(&act.sa_mask);

	act.sa_handler = int_handler;  // SIG_DFL SIG_IGN
	//act.sa_flags = SA_RESETHAND; // SA_ONESHOT
	act.sa_flags = SA_NODEFER;

	sigaddset(&act.sa_mask, SIGQUIT);

	sigaction(SIGINT, &act, NULL);

	while (1)
		sleep(1);

	return 0;
}





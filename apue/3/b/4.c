#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <errno.h>

void do_it(int num)
{
	printf("OUCH\n");
}

int main()
{

	struct sigaction act;
	act.sa_handler = do_it;
	//act.sa_flags = 0;
	act.sa_flags = SA_RESTART;
	
	sigaction(SIGALRM, &act, NULL);

	alarm(3);

	char buf[128];
	memset(buf, 0, 128);

	int n = read(0, buf, 127);
	buf[n] = '\0';

	if (errno == EINTR)
		printf("EINTR\n");

	printf("%s", buf);

	return 0;
}


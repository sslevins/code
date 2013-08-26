#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <signal.h>

void handler(int num)
{
	printf(".");
	fflush(stdout);
}

int main()
{
	int ret = 0;

	signal(SIGALRM, handler);

	struct itimerval timer;
	timer.it_value.tv_sec = 3;
	timer.it_value.tv_usec = 500000;
	timer.it_interval.tv_sec = 1;
	timer.it_interval.tv_usec = 500000;

	ret = setitimer(ITIMER_REAL, &timer, NULL);

	timer.it_value.tv_sec = 1;
	timer.it_value.tv_usec = 0;
	timer.it_interval.tv_sec = 2;
	timer.it_interval.tv_usec = 0;

	struct itimerval old_timer;
	ret = setitimer(ITIMER_REAL, &timer, &old_timer);
	printf("%ld, %ld, %ld, %ld\n", 
				old_timer.it_value.tv_sec, 
				old_timer.it_value.tv_usec,
				old_timer.it_interval.tv_sec,
				old_timer.it_interval.tv_usec);

	setitimer(ITIMER_REAL, old_timer, NULL);

	if (ret == -1) {
		printf("setitimer error\n");
		exit(1);
	}

	while (1)
		pause();

	return 0;
}




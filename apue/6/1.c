#include <stdio.h>
#include <pthread.h>

void * do_it_0(void * p)
{
	int i = 10;
	while (i--)
	{
		printf(".");
		fflush(stdout);
	}
	exit(0);
}

void * do_it_1(void * p)
{
	int i = 100;
	while (i--)
	{
		printf("x");
		fflush(stdout);
		sleep(1);
	}
}

int main()
{
	pthread_t t1;
	pthread_t t2;

	pthread_create(&t1, NULL, do_it_0, NULL);
	pthread_create(&t2, NULL, do_it_1, NULL);

	pthread_join(t1, NULL); // wait();
	pthread_join(t2, NULL);

	return 0;
}

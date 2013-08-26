#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void * do_it(void * p)
{

	//int ret = pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
	int ret = pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL);
	if (ret != 0)
	{
		perror("pthread_setcancelstate");
		exit(1);
	}


	while (1)
	{
		printf(".");
		fflush(stdout);
		sleep(1);
	}
}

int main()
{
	int ret;

	pthread_t a_thread;

	pthread_create(&a_thread, NULL, do_it, NULL);

	sleep(1);
	
	ret = pthread_cancel(a_thread);
	if (ret != 0)
	{
		perror("pthread_cancel");
		exit(1);
	}

	pthread_join(a_thread, NULL);

	printf("hello world!\n");

	return 0;
}



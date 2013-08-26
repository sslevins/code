#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int num = 0;

//pthread_mutex_t lock = { 0, 0, 0, 0, 0, 0, { 0, 0 } };
pthread_mutex_t hello = PTHREAD_MUTEX_INITIALIZER;

void * do_it(void * p)
{
	int i = 10000;
	while (i--)
	{
		//pthread_mutex_lock(&hello);
		num++;
		//pthread_mutex_unlock(&hello);
	}
}

int main()
{
	pthread_t a_thread;
	pthread_t b_thread;


	pthread_create(&a_thread, NULL, do_it, NULL);
	pthread_create(&b_thread, NULL, do_it, NULL);

	pthread_join(a_thread, NULL);
	pthread_join(b_thread, NULL);

	printf("num: %d\n", num);

	return 0;
}

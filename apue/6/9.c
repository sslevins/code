#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

pthread_mutex_t read_lock = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t write_lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t can_read = PTHREAD_COND_INITIALIZER;
pthread_cond_t can_write = PTHREAD_COND_INITIALIZER;

int num = 0;

int flag = 0;

void * do_it_a(void * p)
{
	pthread_mutex_lock(&write_lock);

	if (num != 0)
		pthread_cond_wait(&can_write, &write_lock);

	num = 10;

	pthread_cond_signal(&can_read);

	pthread_mutex_unlock(&write_lock);
}

void * do_it_b(void *p)
{
	pthread_mutex_lock(&write_lock);

	if (num != 0)
		pthread_cond_wait(&can_write, &write_lock);

	num = 100;

	pthread_cond_signal(&can_read);

	pthread_mutex_unlock(&write_lock);
}

int main()
{
	pthread_t a_thread;
	pthread_t b_thread;

	pthread_create(&b_thread, NULL, do_it_a, NULL);
	pthread_create(&a_thread, NULL, do_it_b, NULL);

	int total = 0;

	int i = 2;
	while (i--)
	{
		pthread_mutex_lock(&read_lock);
		if (num == 0)
			pthread_cond_wait(&can_read, &read_lock);
		total += num;
		num = 0;
		pthread_cond_signal(&can_write);
		pthread_mutex_unlock(&read_lock);
	}

	pthread_join(b_thread, NULL);
	pthread_join(a_thread, NULL);

	printf("total: %d\n", total); // 110

	return 0;
}



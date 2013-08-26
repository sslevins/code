#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

char buf[1] = {0};

pthread_mutex_t rlock = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t wlock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t can_read = PTHREAD_COND_INITIALIZER;
pthread_cond_t can_write = PTHREAD_COND_INITIALIZER;

void* write_buf(void * p)
{
	char c;
	int i = 0;
	char arr[52];
	for (c = 'a'; c <= 'z'; c++, i++)
		arr[i] = c;
	for (c = 'A'; c <= 'Z'; c++, i++)
		arr[i] = c;

	i = 0;
	for (i = 0; i < 52; i++)
	{
		pthread_mutex_lock(&wlock);

		if (buf[0] != 0)
			pthread_cond_wait(&can_write, &wlock);

		buf[0] = arr[i];
		printf("write: %c\n", buf[0]);
		fflush(stdout);
		sleep(2);

		pthread_cond_signal(&can_read);
		pthread_mutex_unlock(&wlock);
	}
}

void* read_buf(void *p)
{
	int i = 0;
	char c;
	for (i = 0; i < 52; i++)
	{
		pthread_mutex_lock(&rlock);

		if (buf[0] == 0)
			pthread_cond_wait(&can_read, &rlock);

		printf("read: %c\n", buf[0]);
		fflush(stdout);
		buf[0] = 0;

		sleep(1);

		pthread_cond_signal(&can_write);
		pthread_mutex_unlock(&rlock);
	}
}

int main()
{
	pthread_t a_thread;
	pthread_t b_thread;


	pthread_create(&b_thread, NULL, write_buf, NULL);
	pthread_create(&a_thread, NULL, read_buf, NULL);

	pthread_join(b_thread, NULL);
	pthread_join(a_thread, NULL);

	return 0;
}



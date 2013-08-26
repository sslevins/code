#include <stdio.h>
#include <pthread.h>

int i = 0;

void * do_it_0(void * p)
{
	i++;
}

void * do_it_1(void * p)
{
	i--;
}

int main()
{
	pthread_t t1;
	pthread_t t2;

	pthread_create(&t1, NULL, do_it_0, NULL);
	pthread_create(&t2, NULL, do_it_1, NULL);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

	printf("%d\n", i);

	return 0;
}




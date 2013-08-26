#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void * do_it_0(void * p)
{
	printf("%s\n", p);

	int* x = (int *)malloc(40);

	*x = 100;

	pthread_exit((void *)x);
}

int main()
{
	pthread_t t1;
	
	char * s = "hello world!\n";

	pthread_create(&t1, NULL, do_it_0, s);

	char * p = NULL;
	pthread_join(t1, (void **)(&p));

	printf("%d\n", *p);

	return 0;
}


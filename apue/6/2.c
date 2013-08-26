#include <stdio.h>
#include <pthread.h>

void * do_it_0(void * p)
{
	printf("%s\n", p);
}

int main()
{
	pthread_t t1;
	
	char * s = "hello world!\n";

	pthread_create(&t1, NULL, do_it_0, s);

	pthread_join(t1, NULL);

	return 0;
}




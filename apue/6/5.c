#include <stdio.h>
#include <pthread.h>

void * do_it(void* p)
{
	printf("%s\n", p);
}

int main()
{
	char * s = "hello world!";

	pthread_t t;

	pthread_attr_t t_attr;

	pthread_attr_init(&t_attr);

	pthread_attr_setdetachstate(&t_attr, 
						PTHREAD_CREATE_DETACHED);

	//pthread_create(&t, &t_attr, do_it, s);
	pthread_create(&t, NULL, do_it, s);

	pthread_join(t, NULL);

	pthread_attr_destroy(&t_attr);

	return 0;
}


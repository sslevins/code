#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h>

#define oops(m, x) {perror(m); exit(x);}

int main()
{
	int shmid = shmget(9527, 1024, 0666|IPC_CREAT);
	if (shmid == -1)
		oops("shmget", 1);

	char addr[1024];

	//char * addr = shmat(shmid, NULL, 0);
	shmat(shmid, addr, 0);
	if (addr == (char *)-1)
		oops("shmat", 2);

	char buf[] = "hello world!";	

	strcpy(addr, buf);

	sleep(10);

	if (shmdt(addr) == -1)
		oops("shmdt", 3);

	if (shmctl(shmid, IPC_RMID, NULL) == -1)
		oops("shmctl", 4);
}




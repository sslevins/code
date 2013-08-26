#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main()
{
	int shmid = shmget(9527, 1024, 0666|IPC_CREAT);
	if (shmid == -1)
	{
		printf("shmget error!\n");
		exit(1);
	}

	char * addr = shmat(shmid, NULL, 0);
	if (addr == NULL)
	{
		printf("shmat error!\n");
		exit(2);
	}

	char buf[128] = "";	

	strcpy(buf, addr);

	printf("%s\n", buf);

	shmdt(addr);

}




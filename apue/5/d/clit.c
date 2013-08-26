#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <errno.h>

#define oops(m, x) {perror(m); exit(x);}

void wait_and_lock(int _semid, int _semnum)
{
	struct sembuf ops[2];
	ops[0].sem_num = _semnum;
	ops[0].sem_op = 0;
	ops[0].sem_flg = SEM_UNDO;
	
	ops[1].sem_num = _semnum;
	ops[1].sem_op = +1;
	ops[1].sem_flg = SEM_UNDO;

	semop(_semid, ops, 2); // wait & lock
}

void release_lock(int _semid, int _semnum)
{
	struct sembuf op;
	op.sem_num = _semnum;
	op.sem_op = -1;
	op.sem_flg = SEM_UNDO;
	
	semop(_semid, &op, 1); // release
}

int main()
{
	int semid = semget(1234, 1, 0666|IPC_CREAT);
	if (semid == -1)
		oops("semget", 1);
	
	int shmid = shmget(9527, 1, 0666|IPC_CREAT);
	if (shmid == -1)
		oops("shmget", 2);

	char * addr = shmat(shmid, NULL, 0);
	if (addr == (char *)-1)
		oops("shmat", 2);

	int i = 0;
	char buf;
	for (i = 0; i < 48; i++)
	{
		wait_and_lock(semid, 0);

		strncpy(&buf, addr, 1);

		release_lock(semid, 0);

		printf("c:%c\n", buf);

		sleep(1);
	}

	if (shmdt(addr) == -1)
		oops("shmdt", 3);
}




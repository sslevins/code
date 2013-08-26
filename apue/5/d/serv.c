#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <errno.h>

#define oops(m, x) {perror(m); exit(x);}


union semun {
	int val;
	struct semid_ds *buf;
	unsigned short  *array;
	struct seminfo  *__buf;
};

void init_sem_val(int _semid, 
					int _semnum, int _data)
{
	union semun u;
	u.val = _data;
	semctl(_semid, _semnum, SETVAL, u);
}

void wait_and_lock(int _semid, int _semnum)
{
	struct sembuf op1;
	op1.sem_num = 0;
	op1.sem_op = 0;
	op1.sem_flg = SEM_UNDO;
	
	//semop(_semid, &op1, 1); // wait

	struct sembuf op2;
	op2.sem_num = 0;
	op2.sem_op = +1;
	op2.sem_flg = SEM_UNDO;

	//semop(_semid, &op1, 1); // lock

	struct sembuf ops[2];
	ops[0] = op1;
	ops[1] = op2;

	semop(_semid, ops, 2); // wait & lock
}

void release_lock(int _semid, int _semnum)
{
	struct sembuf op;
	op.sem_num = 0;
	op.sem_op = -1;
	op.sem_flg = SEM_UNDO;
	
	semop(_semid, &op, 1); // release
}

int main()
{
	int semid = semget(1234, 1, 0666|IPC_CREAT);
	if (semid == -1)
		oops("semget", 1);
	
	init_sem_val(semid, 0, 0);

	int shmid = shmget(9527, 1, 0666|IPC_CREAT);
	if (shmid == -1)
		oops("shmget", 2);

	char * addr = shmat(shmid, NULL, 0);
	if (addr == (char *)-1)
		oops("shmat", 2);

	char c;
	int i = 0;
	char buf[48];
	for (c = 'a'; c <= 'z'; c++, i++)
		buf[i] = c;
	for (c = 'A'; c <= 'Z'; c++, i++)
		buf[i] = c;

	i = 0;
	for (i = 0; i < 48; i++)
	{
		wait_and_lock(semid, 0);

		strcpy(addr, &buf[i]);

		release_lock(semid, 0);

		printf("s:%c\n", buf[i]);
		fflush(stdout);

		sleep(2);
	}

	if (shmdt(addr) == -1)
		oops("shmdt", 3);

	if (shmctl(shmid, IPC_RMID, NULL) == -1)
		oops("shmctl", 4);
}

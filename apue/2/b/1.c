#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
	int pid = 0;

	pid = fork();
	if (pid == -1) {
		exit(1);
	} else if (pid == 0) {
		printf("child, pid: %d. ", getpid());
		printf("parent: %d. ", getppid());
		printf("in group: %d.\n", getpgid(0));

		sleep(10);

		printf("child, pid: %d. ", getpid());
		printf("parent: %d. ", getppid());
		printf("in group: %d.\n", getpgid(0));

	} else {
		sleep(3);
		printf("-------------------------\n");
		printf("parent, pid: %d. ", getpid());
		printf("parent: %d. ", getppid());
		printf("in group: %d.\n", getpgid(0));

		setpgid(0, getpgid(getppid()));

		printf("parent, pid: %d. ", getpid());
		printf("parent: %d. ", getppid());
		printf("in group: %d.\n", getpgid(0));
	}

	return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	// execlp("ls", "ls", "-l", "-a", 0);
	//
	char * argv[] = {"ls", "-l", "-a", 0};
	execvp("ls", argv);

	printf("hello world!\n");
	printf("hello world!\n");
	printf("hello world!\n");
	printf("hello world!\n");
	printf("hello world!\n");
}




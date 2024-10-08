#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() 
{
	printf("--------------------------------------------------------------------\n");
    printf("Name: Sarthak\tSection: A2\tRoll No: 58\n");
    printf("--------------------------------------------------------------------\n");
	pid_t pid1, pid2;
	pid1 = fork();
	if (pid1 < 0) {
		printf("Fork failed for child 1\n");
		exit(1);
	}
	else if (pid1 == 0) {
		printf("Child 1 process (PID: %d) listing files:\n", getpid());
		execlp("/bin/ls", "ls", NULL);
		exit(0);
	}
	else {
		pid2 = fork();
		if (pid2 < 0) {
			printf("Fork failed for child 2\n");
			exit(1);
		}
		else if (pid2 == 0) {
			sleep(5);
			printf("Child 2 process (PID: %d, Parent PID: %d) is executing after delay.\n",getpid(), getppid());
			exit(0);
		}
		else {
			printf("Parent process (PID: %d) is waiting for Child 1 (PID: %d) to finish.\n",getpid(), pid1);
			waitpid(pid1, NULL, 0);
			printf("Parent process finished waiting for Child 1.\n");
			printf("Parent process exiting before Child 2 finishes.\n");
			exit(0);
		}
	}
	return 0;
}
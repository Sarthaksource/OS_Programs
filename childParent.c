#include <stdio.h>
#include <unistd.h>

int main()
{
	printf("--------------------------------------------------------------------\n");
    printf("Name: Sarthak\tSection: A2\tRoll No: 58\n");
    printf("--------------------------------------------------------------------\n");
	pid_t pid = fork();
	if(pid<0)
	{
		printf("Failed to create child process");
	}
	else if(pid==0)
	{
		printf("Process is child process, pid: %d\n", getpid());
		printf("Parent process pid: %d\n", getppid());
	}
	else
	{
		printf("Process is parent process, pid: %d\n", getpid());
		printf("Child process pid: %d\n", pid);
	}
	
	return 0;
}
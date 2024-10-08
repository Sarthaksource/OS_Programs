#include <stdio.h>
#include <unistd.h>

int main()
{
	printf("--------------------------------------------------------------------\n") ;
    printf("Name: Sarthak\tSection: A2\tRoll No: 58\n");
    printf("----------------------------------------------------------------------\n");
	int pid = fork();
	printf("%d\n", getpid());

	return 0;
}
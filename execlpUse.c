#include <stdio.h>
#include <unistd.h>

int main() {
	printf("Executing 'ls' command:\n");
	execlp("ls", "ls", NULL);
	perror("execlp failed");
	return 0;
}
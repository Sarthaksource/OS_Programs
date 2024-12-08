#include <stdio.h>

void firstFit(int nb, int blocks[], int np, int processes[])
{
	int allocated[np];

	for(int i=0; i<np; i++)
	{
		allocated[i] = -1;
	}
	for(int i=0; i<np; i++)
	{
		for(int j=0; j<nb; j++)
		{
			if(blocks[j]>=processes[i])
			{
				blocks[j] -= processes[i];
				allocated[i] = j;
				break;
			}
		}
	}

	printf("Process No.\tProcess Size\tBlock No.\n");
	for(int i=0; i<np; i++)
	{
		printf("%d\t\t%d\t\t", i+1, processes[i]);
		if(allocated[i]==-1)
		{
			printf("No free block allocated\n");
		}
		else
		{
			printf("%d\n", allocated[i]+1);
		}
	}
}

int main()
{
	printf("--------------------------------------------------------------------\n");
    printf("Name: Sarthak\tSection: A2\tRoll No: 58\n");
    printf("--------------------------------------------------------------------\n");

	int nb, np;
	printf("Enter the number of free blocks available: ");
	scanf("%d", &nb);
	int blocks[nb];
	for(int i=0; i<nb; i++)
	{
		scanf("%d", &blocks[i]);
	}
	printf("Enter the number of processes: ");
	scanf("%d", &np);
	int processes[np];
	for(int i=0; i<np; i++)
	{
		scanf("%d", &processes[i]);
	}

	firstFit(nb, blocks, np, processes);

	return 0;
}
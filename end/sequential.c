#include <stdio.h>
#include <string.h>

struct file
{
	char name[20];
	int startBlock;
	int numBlock;
};

void sequentialAllocation(struct file files[], int fileCount, char searchFile[])
{
	for(int i=0; i<fileCount; i++)
	{
		if(strcmp(files[i].name, searchFile)==0)
		{
			printf("File Name\tStart Block\tNo. of blocks\tBlocks occupied\n");
			printf("%s\t\t%d\t\t%d\t\t", files[i].name, files[i].startBlock, files[i].numBlock);
			for(int j=0; j<files[i].numBlock; j++)
			{
				printf("%d ", files[i].startBlock + j);
			}
			printf("\n");
			return;
		}
	}
	printf("File not found\n");
}

int main()
{
	printf("--------------------------------------------------------------------\n");
    printf("Name: Sarthak\tSection: A2\tRoll No: 58\n");
    printf("--------------------------------------------------------------------\n");

	int fileCount;
	printf("Enter the number of files: ");
	scanf("%d", &fileCount);
	struct file files[fileCount];

	for(int i=0; i<fileCount; i++)
	{
		printf("Enter the name of file %d: ", i+1);
		scanf("%s", files[i].name);
		printf("Enter the starting block of file %d: ", i+1);
		scanf("%d", &files[i].startBlock);
		printf("Enter the number of blocks allocated to file %d: ", i+1);
		scanf("%d", &files[i].numBlock);
	}
	char searchFile[20];
	printf("Enter the name of files to be searched: ");
	scanf("%s", searchFile);

	sequentialAllocation(files, fileCount, searchFile);
}
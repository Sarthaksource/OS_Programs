#include <stdio.h>

int main()
{
	printf("--------------------------------------------------------------------\n");
    printf("Name: Sarthak\tSection: A2\tRoll No: 58\n");
    printf("--------------------------------------------------------------------\n");

	int frameNum, refSize, pageFault = 0, currFrame = 0;
	printf("Enter the number of frames available: ");
	scanf("%d", &frameNum);
	int frames[frameNum];
	for(int i=0; i<frameNum; i++)
	{
		frames[i] = -1;
	}
	printf("Enter the number of requests: ");
	scanf("%d", &refSize);
	int refString[refSize];
	for(int i=0; i<refSize; i++)
	{
		scanf("%d", &refString[i]);
	}

	for(int i=0; i<refSize; i++)
	{
		int pageHit = 0;

		for(int j=0; j<frameNum; j++)
		{
			if(refString[i] == frames[j])
			{
				pageHit = 1;
				break;
			}
		}
		if(pageHit==0)
		{
			pageFault++;
			frames[currFrame] = refString[i];
			currFrame = (currFrame+1)%frameNum;
		}
	}

	printf("Total number of page faults: %d\n", pageFault);

	return 0;
}
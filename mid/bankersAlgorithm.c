#include<stdio.h>
#include<stdbool.h>

struct Process{
	int max[10];
	int allocated[10];
	int need[10];
};

int no_of_processes, no_of_resources;

void input(struct Process p[no_of_processes], int available[no_of_resources])
{
	for(int i=0; i<no_of_processes; i++)
	{
		printf("For P[%d] process:\n", i);
		printf("Enter the maximum resources required: ");
		for(int j=0; j<no_of_resources; j++)
		{
			scanf("%d", &p[i].max[j]);
		}
		printf("Enter the allocated resources: ");
		for(int j=0; j<no_of_resources; j++)
		{
			scanf("%d", &p[i].allocated[j]);
		}
		for(int j=0; j<no_of_resources; j++)
		{
			p[i].need[j] = p[i].max[j] - p[i].allocated[j];
		}
	}
	printf("Enter the available resources: ");
	for(int i=0; i<no_of_resources; i++)
	{
		scanf("%d", &available[i]);
	}
}

void showTable(struct Process p[no_of_processes])
{
	printf("Process\tMaximum\t\tAllocated\tNeeded\n");
	for(int i=0; i<no_of_processes; i++)
	{
		printf("P%d\t", i);
		for(int j=0; j<no_of_resources; j++)
		{
			printf("%d ", p[i].max[j]);
		}
		printf("\t\t");
		for(int j=0; j<no_of_resources; j++)
		{
			printf("%d ", p[i].allocated[j]);
		}
		printf("\t\t");
		for(int j=0; j<no_of_resources; j++)
		{
			printf("%d ", p[i].need[j]);
		}
		printf("\n");
	}
}

bool applySafeSequence(struct Process p[no_of_processes], int available[no_of_resources], int safeSequence[no_of_processes])
{
	bool finished[no_of_processes];
	for(int i=0; i<no_of_processes; i++)
	{
		finished[i] = false;
	}
	int work[no_of_resources];
	for(int i=0; i<no_of_resources; i++)
	{
		work[i] = available[i];
	}

	int k = 0;
	bool proceed = true;
	while(proceed)
	{
		proceed = false;
		for(int i=0; i<no_of_processes; i++)
		{
			bool flag = true;
			if(finished[i]==false)
			{
				for(int j=0; j<no_of_resources; j++)
				{
					if(p[i].need[j] <= work[j])
					{
						continue;
					}
					else
					{
						flag = false;
						break;
					}
				}

				if(flag==false)
				{
					continue;
				}
				for(int j=0; j<no_of_resources; j++)
				{
					work[j] += p[i].allocated[j];
				}
				finished[i] = true;
				safeSequence[k++] = i;
				proceed = true;
			}
		}
	}

	int i;
	for(i=0; i<no_of_processes && finished[i]==true; i++)
	{
		continue;
	}
	if(i==no_of_processes)
	{
		return true;
	}
	return false;
}


bool isSafeState(struct Process p[no_of_processes], int available[no_of_resources], int safeSequence[no_of_processes])
{
	if(applySafeSequence(p, available, safeSequence)==true)
	{
		return true;
	}
	return false;
}

int main()
{
	printf("Enter the number of processes: ");
	scanf("%d", &no_of_processes);
	printf("Enter the number of resources: ");
	scanf("%d", &no_of_resources);
	struct Process p[no_of_processes];
	int available[no_of_resources];
	input(p, available);

	showTable(p);

	int safeSequence[no_of_processes];

	if(isSafeState(p, available, safeSequence)==true)
	{
		printf("System is in safe state");
		printf("Safe Sequence: ");
		for(int i=0; i<no_of_processes; i++)
		{
			printf("P[%d] ", safeSequence[i]);
		}
	}
	else
	{
		printf("System is in unsafe state");
	}

	return 0;
}
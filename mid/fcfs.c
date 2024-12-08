#include <stdio.h>
#include <stdlib.h>

struct Process
{
	int pid, at, bt, st, ct, rt, tat, wt;
};

int compare(const void* p1, const void* p2)
{
	int a = ((struct Process*)p1)->at;
	int b = ((struct Process*)p2)->at;

	return a<b ? -1 : 1;
}

int main()
{
	printf("--------------------------------------------------------------------\n");
    printf("Name: Sarthak\tSection: A2\tRoll No: 58\n");
    printf("--------------------------------------------------------------------\n");
	int n;
	printf("Enter the number of processes: ");
	scanf("%d", &n);
	struct Process p[n];
	printf("Enter the burst time:");
	for(int i=0; i<n; i++)
	{
		p[i].pid = i+1;
		scanf("%d", &p[i].bt);
	}
	printf("Enter the arrival time:");
	for(int i=0; i<n; i++)
	{
		scanf("%d", &p[i].at);
	}

	qsort((void*)p, n, sizeof(struct Process), compare);

	float ttat = 0, tbt = 0, twt = 0, awt = 0, atat = 0, cpuu = 0, tp = 0;

	for(int i=0; i<n; i++)
	{
		if(i==0)
		{
			p[i].ct = p[i].at + p[i].bt;
		}
		else if(p[i-1].ct <= p[i].at)
		{
			p[i].ct = p[i].at + p[i].bt;
		}
		else
		{
			p[i].ct = p[i-1].ct + p[i].bt;
		}
	
		p[i].tat = p[i].ct - p[i].at;
		p[i].wt = p[i].tat - p[i].bt;
		p[i].rt = p[i].wt;
		p[i].st = p[i].rt + p[i].at;

		tbt += p[i].bt;
		ttat += p[i].tat;
		twt += p[i].wt; 
	}
	float maxct;
	for(int i=0; i<n; i++)
	{
		maxct = 0;
		if(p[i].ct > maxct)
		{
			maxct = p[i].ct;
		}
	}

	atat = ttat/n;
	awt = twt/n;
	cpuu = (tbt/maxct) * 100;
	tp = n/maxct;

	printf("PID\tAT\tBT\tST\tCT\tTAT\tWT\tRT\n");
	for(int i=0; i<n; i++)
	{
		printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].st, p[i].ct, p[i].tat, p[i].wt, p[i].rt);
	}
	printf("\nTotal Turnaround Time: %f\nAverage Turnaround Time: %f\nTotal Waiting Time: %f\nAverage Waiting Time: %f\n", ttat, atat, twt, awt);
	printf("CPU Utilization: %f\nThroughput: %f\n", cpuu, tp);

	return 0;
}
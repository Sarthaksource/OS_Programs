#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

struct Process
{
	int pid, at, bt, st, ct;
	float tat, wt, rt;
};

int findMax(int a, int b)
{
	return (a>b) ? a : b;
}

int findMin(int a, int b)
{
	return (a<b) ? a : b;
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
	int bt_remaining[n];
	for(int i=0; i<n; i++)
	{
		p[i].pid = i;
		printf("Enter the arrival time and burst time for pid %d: ", i);
		scanf("%d %d", &p[i].at, &p[i].bt);
		bt_remaining[i] = p[i].bt;
	}
	int completed = 0;
	int ttat = 0, twt = 0, trt = 0;
	int prev_time = 0, current_time = 0, total_idle_time = 0;
	
	bool is_first = true;
	bool is_complete[n];
	for(int i=0; i<n; i++)
	{
		is_complete[i] = false;
	}

	while(completed!=n)
	{
		int min_bt = INT_MAX;
		int min_index = -1;

		for(int i=0; i<n; i++)
		{
			if(p[i].at<=current_time && is_complete[i]==false)
			{
				if(bt_remaining[i]<min_bt)
				{
					min_bt = bt_remaining[i];
					min_index = i;
				}
				if(bt_remaining[i]==min_bt)
				{
					if(p[i].at<p[min_index].at)
					{
						min_index = i;
					}
				}
			}
		}
		if(min_index==-1)
		{
			current_time++;
		}
		else
		{
			if(bt_remaining[min_index]==p[min_index].bt)
			{
				p[min_index].st = current_time;
				total_idle_time += (is_first==true) ? 0 : p[min_index].st - prev_time;
				is_first = false;
			}
			current_time++;
			prev_time = current_time;
			bt_remaining[min_index]--;
			
			if(bt_remaining[min_index]==0)
			{
				p[min_index].ct = current_time;
				p[min_index].tat = p[min_index].ct - p[min_index].at;
				p[min_index].wt = p[min_index].tat - p[min_index].bt;
				p[min_index].rt = p[min_index].st - p[min_index].at;

				ttat += p[min_index].tat;
				twt += p[min_index].wt;
				trt += p[min_index].rt;
				
				completed++;
				is_complete[min_index] = true;
			}
		}
	}

	int max_ct = INT_MIN;
	int min_at = INT_MAX;

	for(int i=0; i<n; i++)
	{
		max_ct = findMax(max_ct, p[i].ct);
		min_at = findMin(min_at, p[i].at);
	}

	int total_process_cycle = max_ct - min_at;

	float cpuu = (float)(total_process_cycle - total_idle_time)/total_process_cycle * 100;
	float tp = n/(float)total_process_cycle;

	printf("\nProcess No.\tAT\tCPU Burst Time\tCT\tTAT\tWT\tRT\n");
	for(int i=0;i<n;i++)
		printf("P%d\t\t%d\t%d\t\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt,p[i].rt);
	printf("\n");
	printf("\nAverage Turn Around time= %f ",(float)ttat/n);
	printf("\nAverage Waiting Time= %f ",(float)twt/n);
	printf("\nAverage Response Time= %f ",(float)trt/n);
	printf("\nThroughput= %f",tp);
	printf("\nCPU Utilization(Percentage)= %f\n",cpuu);

	return 0;
}

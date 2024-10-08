#include<stdio.h>
#include<stdbool.h>
struct process_struct
{
	int at;
	int bt;
	int priority;
	int ct,wt,tat,rt,start_time;
}ps[100];

int main()
{
	printf("--------------------------------------------------------------------\n");
    printf("Name: Sarthak\tSection: A2\tRoll No: 58\n");
    printf("--------------------------------------------------------------------\n");
	int n;
	int current_time = 0;
	int completed = 0;
	printf("Enter total number of processes");
	scanf("%d",&n);
	float sum_tat=0,sum_wt=0,sum_rt=0;
	bool is_completed[100];
	for(int i=0; i<n; i++)
	{
		is_completed[i] = false;
	}
	int i;

	printf("\nEnter Process Arrival Time\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&ps[i].at);
	}
	printf("\nEnter Process Burst Time\n");
	for(i=0;i<n;i++)
		scanf("%d",&ps[i].bt);

	printf("\nEnter Priority\n");
	for(i=0;i<n;i++)
		scanf("%d",&ps[i].priority);
	
	bool is_first = true;
	int total_idle_time = 0, prev_time = 0;

	while(completed!=n)
	{
		int max_index = -1;
		int maximum = -1;
		for(int i = 0; i < n; i++) {
			if(ps[i].at <= current_time && is_completed[i] == 0) {
				if(ps[i].priority > maximum) {
					maximum = ps[i].priority;
					max_index = i;
				}
				if(ps[i].priority== maximum) {
					if(ps[i].at < ps[max_index].at) {
						maximum= ps[i].priority;
						max_index = i;
					}
				}
			}
		}
		if(max_index==-1)
		{
			current_time++;
		}
		else
		{
			if(bt_remaining[max_index]==ps[max_index].bt)
			{
				ps[max_index].start_time = current_time;
				total_idle_time += (is_first==true) ? 0 : p[min_index].start_time - prev_time;
				is_first = false;				
			}
			bt_remaining[max_index]--;
			current_time++;
			prev_time = current_time;
			if(bt_remaining[max_index]==0)
			{
				ps[max_index].ct = ps[max_index].start_time + ps[max_index].bt;
				ps[max_index].tat = ps[max_index].ct - ps[max_index].at;
				ps[max_index].wt= ps[max_index].tat - ps[max_index].bt;
				ps[max_index].rt = ps[max_index].start_time - ps[max_index].at;
				sum_tat +=ps[max_index].tat;
				sum_wt += ps[max_index].wt;
				sum_rt += ps[max_index].rt;
				completed++;
				is_completed[max_index]=true;
				printf("Max=%d ", ps[max_index].ct);
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		printf("%.2d ",ps[i].ct);
	}
	printf("Average Turnaround Time: \n%.2f",sum_tat/n);
	printf("Average Waiting Time: \n%.2f",sum_wt/n);
	printf("Average Response Time: \n%.2f",sum_rt/n);
	return 0;
}
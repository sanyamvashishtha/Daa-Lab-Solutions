#include<stdio.h>
int main()
{
	int bt[20],p[30],wt[20],tat[2],i,j,n,total=0,pos,temp;//bt is the burst time of each process, p is the process number, wt is the waiting time of each process, tat is the turnaround time of each process
	float avg_wt,avg_tat;//avg_wt is the average waiting time, avg_tat is the average turnaround time
	printf("Enter number of process:");//Enter the number of processes
	scanf("%d",&n);
	printf("Enter Burst Time:\n");
	//Read the burst time of each process
	for (i=0;i<n;i++)
	{
		printf("p%d:",i+1);
		scanf("%d",&bt[i]);
		p[i]=i+1;
	}
	//Sort the processes based on the burst time
	for (i=0;i<n;i++)
	{
		//Find the process with the minimum burst time
		pos=i;
		for (j=i+1;j<n;j++)
		{
			if(bt[j]<bt[pos])
			pos=j;
		}
		temp=bt[i];
		bt[i]=bt[pos];
		bt[pos]=temp;
		temp=p[i];
		p[i]=p[pos];
		p[pos]=temp;
	}
	//Calculate the waiting time and turnaround time of each process
	wt[0]=0;
	for (i=1;i<n;i++)
	{
		wt[i]=0;
		for(j=0;j<i;j++)
		wt[i]+=bt[j];
		total+=wt[i];
	}
	//Calculate the average waiting time and average turnaround time
	avg_wt=(float)total/n;
	total=0;
	printf("Process\tBurstTime\tWaitingTime\tTurnaround Time");
	//Print the process number, burst time, waiting time and turnaround time of each process
	for(i=0;i<n;i++)
	{
		tat[i]=bt[i]+wt[i];
		total+=tat[i];
		printf("\np%d \t %d \t %d \t %d",p[i],bt[i],wt[i],tat[i]);
	}
	//Print the average waiting time and average turnaround time
	avg_tat=(float)total/n;
	printf("\nAverage Waiting Time=%f",avg_wt);
	printf("\nAverage Turnaround Time=%f",avg_tat);
	
}
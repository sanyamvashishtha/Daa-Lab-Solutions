#include<stdio.h>
void main()
{
	int i,j,n,t,turn[20],burst[20],p[20],wt[20],c[20];//n is the number of processes, burst is the burst time of each process, p is the priority of each process, c is the process number
	float await,aturn,twait=0,tturn=0;//await is the average waiting time, aturn is the average turn around time
	printf("Enter the value of n: ");//Enter the number of processes
	scanf("%d",&n);
	printf("Enter the process no, burst and arrivaltime:");
	//Read the process number, burst time and arrival time of each process
	for(i=0;i<n;i++)
	{
		scanf("%d",&c[i]);
		scanf("%d",&burst[i]);
		scanf("%d",&p[i]);
	}
	//Sort the processes based on the priority
	for(i=0;i<n;i++)
	for(j=i+1;j<n;j++)
	{
		if(p[i]>p[j])
		{
			t=p[i];
			p[i]=p[j];
			p[j]=t;
			t=burst[i];
			burst[i]=burst[j];
			burst[j]=t;
			t=c[i];
			c[i]=c[j];
			c[j]=t;
		}
	}
	//Calculate the waiting time and turn around time of each process
	for(i=0;i<n;i++)
	if(i==0)
	{	wt[i]=0;
		turn[i]=burst[i];
	}
	else
	{
		turn[i]=turn[i-1]+burst[i];
		wt[i]=turn[i]-burst[i];
		twait=twait+wt[i];
		tturn=tturn+turn[i];
	}
	//Calculate the average waiting time and average turn around time
	await=twait/n;
	aturn=tturn/n;
	printf("pno\tbtime\tatime\twtime\tttime\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t%d\t%d\t%d\t%d\n",c[i],burst[i],p[i],wt[i],turn[i]);
	}
	printf("The average waiting time is:%f\n",await);
	printf("The average turn around time is:%f",aturn);
}
#include<stdio.h>
void main(){
	int process_number,i=0,j=1,total_time=0,total_turn_time=0;//i is the process number and j is the process number
	int process[20][3];	//process[0] is the burst time, process[1] is the waiting time, process[2] is the turnaround time
	printf("Enter total number of processes(maximum 20):");//Enter the number of processes
	scanf("%d",&process_number);//Read the number of processes
	printf("Enter Process Burst Time\n");//Enter the burst time of each process
	//Read the burst time of each process
	for(i=0;i<process_number;i++){
		printf("P[%d]:",i+1);
		scanf("%d",&process[i][0]);
		process[i][1]=0;
		process[i][2]=0;
	}
	//Sort the processes based on the burst time
	process[0][1]=0;
	printf("Process\t\tBurst Time\tWaiting Time\tTurnaround Time");
	//Calculate the waiting time and turnaround time of each process
	for (i=0;i<process_number;i++){
		if(i > 0){
			process[i][1]=process[i-1][2];
		}
		process[i][2]=process[i][0]+process[i][1];
	}
	printf("\n");
	//Print the process number, burst time, waiting time and turnaround time of each process
	for(i=0;i<process_number;i++){
		printf("P[%d]\t\t%d\t\t%d\t\t%d",i+1,process[i][0],process[i][1],process[i][2]);
		total_time+=process[i][1];
		total_turn_time+=process[i][2];
		printf("\n");
	}
	printf("Average Waiting Time:%d\n",(total_time/process_number));
	printf("Average Turnaround Time:%d",(total_turn_time/process_number));
	
}
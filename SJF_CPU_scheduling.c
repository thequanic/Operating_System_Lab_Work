#include <stdio.h>
#include <limits.h>
typedef struct process
{
    int pid;
    int arrival_time;
    int brust_time;
    int comp_time;
    int turnaround_time;
    int waiting_time;
    int rem_time;  //time remaining;
}process;
//storing process as struct so prog is efficient

int main()
{
    int n;
    printf("Enter number of processes:");
    scanf("%d",&n);

    //array to contain processes
    process array[n];

    printf("Enter pid, arrival time and brust time for %d processes:\n",n);

    int i;
    for(i=0;i<n;i++)
    {
        printf("Enter for process %d:",i+1);
        scanf("%d %d %d",&array[i].pid,&array[i].arrival_time,&array[i].brust_time);
        array[i].rem_time=array[i].brust_time;

        //sorting processes 
        if(i>0)
        {
            process key = array[i];
            int j = i - 1;
            while (j >= 0 && array[j].arrival_time > key.arrival_time) {
                array[j + 1] = array[j];
                j = j - 1;
            }
            array[j + 1] = key;
        }
    }

    int time=array[0].arrival_time; 
    int idle_time=0;    
    int processes_completed=0;

    while(processes_completed<n)
    {
        //for each unit of time we will find process with min rem_time. 
        //keep in mind that process must have arrival time less than or equal to current time unit.
        int min_index=-1,min_rem_time=INT_MAX;
        for(i=0;i<n;i++)
        {
            if(array[i].arrival_time<=time && array[i].rem_time!=0)
            {
                if(array[i].rem_time<min_rem_time)
                {
                    min_index=i;
                    min_rem_time=array[i].rem_time;
                }
            }
        }

        if(min_index==-1)
        {
            //this is idle condition
            time++;
            idle_time++;
            continue;
        }

        time+=array[min_index].brust_time;
        array[min_index].rem_time-=array[min_index].brust_time; //result must be zero
        array[min_index].comp_time=time;
        processes_completed++;

    }

    for(i=0;i<n;i++)
    {
        array[i].turnaround_time=array[i].comp_time-array[i].arrival_time;
        array[i].waiting_time=array[i].turnaround_time-array[i].brust_time;
    }

    //printing results
    float cpu_utilization=((time-idle_time)/(float)time)*100;
    float averg_wait_time=0,averg_turn_time=0;
    for(i=0;i<n;i++)
    {
        printf("\nPid arrival_time brust_time waiting_time completion_time turnaround_time\n");
        printf("%3d %12d %10d %12d %15d %15d\n",array[i].pid,array[i].arrival_time,array[i].brust_time,array[i].waiting_time,array[i].comp_time,array[i].turnaround_time);
        averg_wait_time+=array[i].waiting_time;
        averg_turn_time+=array[i].turnaround_time;
    }

    printf("\nAverage Waiting Time=%f, Average turn around time=%f",averg_wait_time/n,averg_turn_time/n);
    printf("\nTotal time taken by cpu to complete all processes: %d",time);
    printf("\nTotal idle time of cpu to complete all processes: %d",idle_time);
    printf("\nCPU UTILIZATION: %f percent",cpu_utilization);


} 
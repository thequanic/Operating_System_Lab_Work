#include <stdio.h>
typedef struct process
{
    int pid;
    int arrival_time;
    int brust_time;
    int comp_time;
    int turnaround_time;
    int waiting_time;
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

        //sorting processes according to arrival time using insertion sort
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

    for(i=0;i<n;i++)
    {
        //calculating completion time, awaiting_time and turn around time for each process
        if(i==0)
        {
            //for first process waiting time will be zero //comp_time=arrival+brust //turn around=comp-arrival
            array[i].comp_time=array[i].arrival_time+array[i].brust_time;
            array[i].waiting_time=0;
            array[i].turnaround_time=array[i].comp_time-array[i].arrival_time;

        }
        else
        {
            //comp=comp of previous process + brust // turnaround= comp-arrival //waiting=turnaround-brust
            array[i].comp_time=array[i-1].comp_time+array[i].brust_time;
            array[i].turnaround_time=array[i].comp_time-array[i].arrival_time;
            array[i].waiting_time=array[i].turnaround_time-array[i].brust_time;
        }
    }

    //printing results
    float averg_wait_time=0,averg_turn_time=0;
    for(i=0;i<n;i++)
    {
        printf("\nPid arrival_time brust_time waiting_time completion_time turnaround_time\n");
        printf("%3d %12d %10d %12d %15d %15d\n",array[i].pid,array[i].arrival_time,array[i].brust_time,array[i].waiting_time,array[i].comp_time,array[i].turnaround_time);
        averg_wait_time+=array[i].waiting_time;
        averg_turn_time+=array[i].turnaround_time;
    }

    printf("\nAverage Waiting Time=%f, Average turn around time=%f",averg_wait_time/n,averg_turn_time/n);


}
#include <stdio.h>

{
    int pid;
    int arrival_time;
    int brust_time;
    int comp_time;
    int turnaround_time;
    int waiting_time;
    int res_time; //response time
    int rem_time; //remaining brust time
}process;

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
        array[i].res_time=-1;
        array[i].rem_time=array[i].brust_time;
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

    int quant;
    printf("Enter time quant:");
    scanf("%d",&quant);

    int time=array[0].arrival_time; //we have start time with arrival time of first process
    int processes_completed=0;
    int idle_time=0;

    int temp=0;

    while(processes_completed<n)
    {
        if(array[temp].rem_time<=0) //if process is already completed
        {
            if(temp!=n-1 && array[temp+1].arrival_time<=time)
            {
                temp++;
            }
            else
            {
                temp=0;
            }
            continue;
        }
         
        if(array[temp].res_time==-1){array[temp].res_time=time-array[temp].arrival_time;}
        array[temp].rem_time-=quant;

        if(array[temp].rem_time<=0)
        {
            //if current process has compeleted its overall execution
            time=time+quant+array[temp].rem_time; //in the case rem_time was 2 but quant was 3. 
                                                  //to adjust this condition we have add rem_time
            array[temp].comp_time=time;
            processes_completed++;
        }
        else
        {
            time+=quant;
        }

        if(temp!=n-1 && array[temp+1].arrival_time<=time)
        {
            temp++;
        }
        else
        {
            temp=0;
        }


    }

}
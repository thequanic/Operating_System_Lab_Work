#include <stdio.h>

typedef struct process
{
    int pid;
    int arrival_time;
    int brust_time;
    int comp_time;
    int turnaround_time;
    int waiting_time;

    int res_time; //response time
    int rem_time; //remaining brust time

    int in_q;     //to check whether process is inside queue or not. if its value is 0 process is outside queue
}process;
//storing process as struct so prog is efficient

//queue and its functions //queue will store index of process from the array
int front=-1,end=-1;

void enqueue(int queue[],int n,int p)    
{
    if((end+1)%n==front)
    {
        printf("\nOverflow while enqueue %d\n",p);
        return;
    }
    if(end==-1)
    {
        front=0;
    }
    end=(end+1)%n;
    queue[end]=p;

}

int dequeue(int queue[],int n)
{
    if(end==-1)
    {
        //printf("\nUnderflow while dequeue\n");
        return -1 ;
    }
    int temp=queue[front];
    if(front==end)
    {
        front=-1;
        end=-1;
    }
    else
    {
        front=(front+1)%n;
    }
    return temp;
}



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
        array[i].in_q=0;

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

    int queue[n];

    enqueue(queue,n,0);             //enqueue first process and set in_q to 1 as process go inside queue 
    array[0].in_q=1;
    int time=array[0].arrival_time; //we have start time with arrival time of first process
    int processes_completed=0;
    int idle_time=0;

    while(processes_completed<n)
    {
        

        int temp=dequeue(queue,n);  //dequeue one process from queue. Actually the index of that process in array

        if(temp==-1)//idle condition
        {
            idle_time++;
            time++;

            for(i=0;i<n;i++) //checking for processes that are ready to go to queue if not already in it
            {
                if(array[i].arrival_time<=time && array[i].res_time==-1 && array[i].in_q==0)
                {
                    enqueue(queue,n,i);
                    array[i].in_q=1;

                }
            }

            continue;

        }

        array[temp].in_q=0;          //set in_q t zero as process is outside queue
        
        if(array[temp].res_time==-1){array[temp].res_time=time-array[temp].arrival_time;}
        array[temp].rem_time-=quant;


        if(array[temp].rem_time<=0)
        {
            //if current process has compeleted its overall execution
            time=time+quant+array[temp].rem_time; //in the case rem_time was 2 but quant was 3. 
                                                  //to adjust this condition we have add rem_time
            array[temp].comp_time=time;
            processes_completed++;
            for(i=0;i<n;i++) //checking for processes that are ready to go to queue if not already in it
            {
                if(array[i].arrival_time<=time && array[i].res_time==-1 && array[i].in_q==0)
                {
                    enqueue(queue,n,i);
                    array[i].in_q=1;

                }
            }
        }
        else
        {
            time+=quant;
            for(i=0;i<n;i++) //checking for processes that are ready to go to queue if not already in it
            {
                if(array[i].arrival_time<=time && array[i].res_time==-1 && array[i].in_q==0)
                {
                    enqueue(queue,n,i);
                    array[i].in_q=1;

                }
            }
            enqueue(queue,n,temp); //enqueue process executed above if it is not compeleted
            array[temp].in_q=1;

            
        }


    }

    for(i=0;i<n;i++)
    {
        array[i].turnaround_time=array[i].comp_time-array[i].arrival_time;
        array[i].waiting_time=array[i].turnaround_time-array[i].brust_time;
    }

    //printing results
    float averg_wait_time=0,averg_turn_time=0;
    float cpu_utilization=((time-idle_time)/(float)time)*100;
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
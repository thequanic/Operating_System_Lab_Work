#include <stdio.h>

typedef struct process
{
    int processId;
    int arrivalTime;
    int brustTime;
    int waitingTime;
    int tat;
    int compTime;
    int responseTime;  
}process;


int front=-1,end=-1;

void enqueue(process queue[],int n,int p)
{
    if((end+1)%n==front)
    {
        printf("\nOverflow while enqueue\n");
        return;
    }

    if(end==-1)
    {
        front=0;
    }

    end=(end+1)%n;

    queue[end]=p;

    

}

int dequeue(process queue[],int n)
{
    if(end==-1)
    {
        printf("\nUnderflow while dequeue\n");
        return;
    }

    process temp=queue[front];

    if(front==end)
    {
        front=-1;
    }

    front=(front+1)%n;

    return temp;



}

int main()
{
    int n;
    printf("Enter number of processes:");
    scanf("%d",&n);

    process arr[n],queue[n];
    printf("Enter process id, arrival time, brust time:");
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d",arr[i].processId,arr[i].arrivalTime,arr[i].brustTime);
        arr[i].waitTime=0;
        arr[i].tat=0;
        arr[i].compTime=0;
        arr[i].responseTime=0;

        if(i>0)
        {
            int j=i-1;
            process key=arr[i];

            while(key.arrivalTime<arr[j].arrivalTime && j>=0)
            {
                arr[j+1]=arr[j];
                j--;
            }
            arr[j+1]=key;
        }

    }

    int time=0,quant=0;

    printf("Enter time quant:");
    scanf("%d",&quant);

    i=0;

    while(i<n)
    {
         
    }



    // enqueue(queue,5,1);
    // enqueue(queue,5,2);
    // enqueue(queue,5,3);
    // enqueue(queue,5,4);
    // enqueue(queue,5,5);
    // enqueue(queue,5,6);
    // dequeue(queue,5);
    // enqueue(queue,5,7);
    
    // int i;
    // for(i=0;i<5;i++){printf("%d",queue[i]);}

    
    return 0;
}
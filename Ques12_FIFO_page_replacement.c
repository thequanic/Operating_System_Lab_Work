#include <stdio.h>

int front=-1,end=-1;

int dequeue(int queue[],int n)
{
    if(end==-1)
    {
        printf("\nUnderflow while dequeue\n");
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

void enqueue(int queue[],int n,int p)    
{
    if((end+1)%n==front)
    {
        dequeue(queue,n);
    }
    if(end==-1)
    {
        front=0;
    }
    end=(end+1)%n;
    queue[end]=p;

}



int search(int queue[],int n,int value)
{
    if(end==-1)
    {
        return 0 ;
    }

    int pointer=front;

    while(pointer!=end)
    {
        if(queue[pointer]==value)
        {
            return 1;
        }
        pointer=(pointer+1)%n;
    }

    if(queue[end]==value){return 1;}

    return 0;
}



int main()
{
    printf("Enter number of page frames:");
    int n;
    scanf("%d",&n);

    int queue[n];

    int m;
    printf("Enter number of page references:");
    scanf("%d",&m);

    int arr[m];
    int i;
    printf("Enter sequence of page reference/access:");
    for(i=0;i<m;i++)
    {
        scanf("%d",&arr[i]);
    }

    int page_faults=0;

    for(i=0;i<m;i++)
    {
        if(!search(queue,n,arr[i]))
        {
            page_faults++;
            enqueue(queue,n,arr[i]);
        }
    }

    printf("\nTotal number of page faults: %d",page_faults);
    printf("\nTotal number of hits: %d",m-page_faults);

    
    return 0; 
}
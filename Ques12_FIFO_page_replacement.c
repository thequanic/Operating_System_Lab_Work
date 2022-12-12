#include <stdio.h>

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

int main()
{
    printf("Enter number of page frames:");
    int n;
    scanf("%d",&n);

    
    return 0; 
}
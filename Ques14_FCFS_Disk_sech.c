#include <stdio.h>
int main()
{
    int n;
    printf("Enter number of requests:");
    scanf("%d",&n);

    int i;
    int arr[n];

    printf("Enter requests:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",arr+i);
    }

    int head;
    printf("Enter initial position of head:");
    scanf("%d",&head);

    int seektime;
    printf("Enter seek time:");
    scanf("%d",&seektime);

    int seekTime[n];
    int count=0;
    int totalSeekTime=0;
    for(i=0;i<n;i++)
    {
        int temp=arr[i]>head?arr[i]-head:head-arr[i];
        head=arr[i];

        count+=temp;
        totalSeekTime=temp*seektime;
        seekTime[i]=totalSeekTime;
    }

    printf("\nRequest\tSeek_Time");
    for(i=0;i<n;i++)
    {
        printf("\n%7d\t%9d",arr[i],seekTime[i]);
    }
    
    printf("\n\nTotal seek operations: %d",count);
    printf("\nTotal seek time: %d",totalSeekTime);

}
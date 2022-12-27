#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
int main()
{
    int n;
    printf("Enter number of requests:");
    scanf("%d",&n);

    int i,j;
    int arr[n];
    int visited[n];

    printf("Enter requests:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",arr+i);
        visited[i]=0;
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
    for(j=0;j<n;j++)
    {
        int min_index=-1,min=INT_MAX;
        for(i=0;i<n;i++)
        {
            if(arr[i]!=head && visited[i]==0 && abs(head-arr[i])<min)
            {
                min=abs(head-arr[i]);
                min_index=i;
            }
        }
        int temp=abs(head-arr[min_index]);
        head=arr[min_index];

        count+=temp;
        totalSeekTime+=temp*seektime;
        seekTime[min_index]=totalSeekTime;

        visited[min_index]=1;
    }

    printf("\nRequest\tSeek_Time");
    for(i=0;i<n;i++)
    {
        printf("\n%7d\t%9d",arr[i],seekTime[i]);
    }
    
    printf("\n\nTotal seek operations: %d",count);
    printf("\nTotal seek time: %d",totalSeekTime);

}
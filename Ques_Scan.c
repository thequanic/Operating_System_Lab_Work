#include <stdio.h>
//Assuming direction from right to left
int main()
{
    int n;
    printf("Enter number of requests:");
    scanf("%d",&n);

    int i;
    int arr[n];

    printf("Enter requests:");
    int k=-1;
    for(int i=0;i<n;i++)
    {
        scanf("%d",arr+i);
        if(i>0)
        {
            int key=arr[i];
            int j=i-1;
            while(arr[j]>key&&j>=0)
            {
                arr[j+1]=arr[j];
                j--;
            }
            arr[j+1]=key;
        }
        if(arr[i]<=50){k=i;}
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

    for(int i=k;i>=0;i--)
    {
        int temp=head-arr[i];
        head=arr[i];

        count+=temp;
        seekTime[i]=temp*seektime;
        totalSeekTime+=seekTime[i];
    }

    int temp=head-0;
    head=0;
    count+=temp;
    totalSeekTime+=temp*seektime;

    for(int i=k+1;i<n;i++)
    {
        int temp=arr[i]-head;
        head=arr[i];

        count+=temp;
        seekTime[i]=temp*seektime;
        totalSeekTime+=seekTime[i];
    }

    printf("\nRequest\tSeek_Time");
    for(i=0;i<n;i++)
    {
        printf("\n%7d\t%9d",arr[i],seekTime[i]);
    }
    
    printf("\n\nTotal seek operations: %d",count);
    printf("\nTotal seek time: %d",totalSeekTime);



    return 0;
}
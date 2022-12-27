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

    printf("\nEnter 1 if head moves right to left and enter 2 if head moves left to right\n");
    printf("Enter your choice:");
    int choice;
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:
        {
            int k=-1;
            for(int i=0;i<n;i++)
            {
                if(arr[i]<=head){k=i;}
            }
            for(int i=k;i>=0;i--)
            {
                int temp=head-arr[i];
                head=arr[i];

                count+=temp;
                totalSeekTime+=temp*seektime;
                seekTime[i]=totalSeekTime;
            }

            int temp=head-0;
            head=0;
            count+=temp;
            totalSeekTime+=temp*seektime;

            temp=199-head;
            head=199;
            count+=temp;
            totalSeekTime+=temp*seektime;

            for(int i=n-1;i>k;i--)
            {
                int temp=head-arr[i];
                head=arr[i];

                count+=temp;
                totalSeekTime+=temp*seektime;
                seekTime[i]=totalSeekTime;
            }
           
            break;
        }

        case 2:
        {

            int k=-1;
            for(int i=0;i<n;i++)
            {
                if(arr[i]<head){k=i;}
            }
            for(int i=k+1;i<n;i++)
            {
                int temp=arr[i]-head;
                head=arr[i];

                count+=temp;
                totalSeekTime+=temp*seektime;
                seekTime[i]=totalSeekTime;
            }

            int temp=199-head; //assuming last disk to be 199
            head=199;
            count+=temp;
            totalSeekTime+=temp*seektime;

            temp=head-0;
            head=0;
            count+=temp;
            totalSeekTime+=temp*seektime;

            for(int i=0;i<=k;i++)
            {
                int temp=arr[i]-head;
                head=arr[i];

                count+=temp;
                totalSeekTime+=temp*seektime;
                seekTime[i]=totalSeekTime;
            }
            
        }
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
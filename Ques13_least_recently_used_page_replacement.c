#include <stdio.h>
#include <limits.h>

int main()
{
    printf("Enter number of page frames:");
    int n;
    scanf("%d",&n);

    int frames[n];
    int last_time_used[n];

    int i;
    for(i=0;i<n;i++){frames[i]=-1;last_time_used[i]=-1;}



    int m;
    printf("Enter number of page references:");
    scanf("%d",&m);

    int arr[m];
    
    printf("Enter sequence of page reference/access:");
    for(i=0;i<m;i++)
    {
        scanf("%d",&arr[i]);
    }

    int page_faults=0;
    int time=0;

    for(i=0;i<m;i++)
    {
        int j;

        int hit_flag=0;
        for(j=0;j<n;j++)
        {
            if(arr[i]==frames[j])
            {

                hit_flag=1;
                last_time_used[j]=time;
                time++;
                break;
            }
        }

        if(hit_flag==1){continue;}

        int min=INT_MAX,min_index=-1;
        for(j=0;j<n;j++)
        {
            if(last_time_used[j]<min)
            {
                min=last_time_used[j];
                min_index=j;
            }
        }

        frames[min_index]=arr[i];
        last_time_used[min_index]=time;
        time++;

        page_faults++;



    }

    printf("\nTotal number of page faults: %d",page_faults);
    printf("\nTotal number of hits: %d",m-page_faults);

    
    return 0; 
}
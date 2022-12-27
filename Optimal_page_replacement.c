#include <stdio.h>
#include <limits.h>

int main()
{
    printf("Enter number of page frames:");
    int n;
    scanf("%d",&n);

    int frames[n];
    int chance[n]; //chance of same frame to be used in future //higher the value lesser the chance

    int i;
    for(i=0;i<n;i++){frames[i]=-1;chance[i]=INT_MAX;}

    
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

    
    for(i=0;i<m;i++)
    {
        int j,flag=0;
        for(j=0;j<n;j++)
        {
            if(arr[i]==frames[j])
            {
                flag=1; //hit
                continue;
            }
        }

        if(flag==1){continue;}

        page_faults++; //miss
   
            int max_index=-1,max=INT_MIN;
            for(j=0;j<n;j++)
            {
                if(chance[j]>max)
                {
                    max=chance[j];
                    max_index=j;
                }
            }

            frames[max_index]=arr[i];
            chance[max_index]=0;

            for(j=i+1;j<m;j++)
            {
                if(arr[i]==arr[j])
                {
                    break;
                }

                chance[max_index]++;
            }

        
    }

    printf("\nTotal number of page faults: %d",page_faults);
    printf("\nTotal number of hits: %d",m-page_faults);


    return 0;
}
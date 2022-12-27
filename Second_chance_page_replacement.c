#include <stdio.h>
#include <limits.h>

int main()
{
    printf("Enter number of page frames:");
    int n;
    scanf("%d",&n);

    int frames[n];
    int reference_bit[n];
    int frame_input_time[n];

    int i;
    for(i=0;i<n;i++){frames[i]=-1;frame_input_time[i]=-1;reference_bit[i]=0;}



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
                reference_bit[j]=1;
                time++;
                break;
            }
        }

        if(hit_flag==1)
        {
           
            continue;
        }

        int insert=arr[i];
        int pos_of_arr_i=-1;
        while(1)
        {
            
            int min=INT_MAX,min_index=-1;
            for(j=0;j<n;j++)
            {
                if(frame_input_time[j]<min)
                {
                    min=frame_input_time[j];
                    min_index=j;
                }
            }

            if(insert==arr[i])
            {
                pos_of_arr_i=min_index;
            }
            else
            {
                frame_input_time[pos_of_arr_i]++;
            }

            int temp=frames[min_index];
            int temp_bit=reference_bit[min_index];
            frames[min_index]=insert;
            frame_input_time[min_index]=time;
            reference_bit[min_index]=0;
            time++;

            if(temp_bit==0)
            {
                frame_input_time[pos_of_arr_i]++;
                break;
            }
            insert=temp;
        }

        page_faults++;

        

    }

    printf("\nTotal number of page faults: %d",page_faults);
    printf("\nTotal number of hits: %d",m-page_faults);

    
    return 0; 
}
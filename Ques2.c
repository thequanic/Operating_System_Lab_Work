#include <stdio.h>
#include <unistd.h>
int main()
{
    int arr[10]={1,2,3,4,5,6,7,8,9,0};
    int n=fork();
    if(n>0)
    {
        int even=0;
        int i;
        for(i=0;i<10;i++)
        {
            if(arr[i]%2==0)
            {
                even+=arr[i];
            }
        }
        printf("Sum of even numbers by prarent: %d\n",even);
    }
    else
    {
        int odd=0;
        int i;
        for(i=0;i<10;i++)
        {
            if(arr[i]%2!=0)
            {
                odd+=arr[i];
            }
        }
        printf("Sum of odd numbers by child: %d\n",odd);
    }
}
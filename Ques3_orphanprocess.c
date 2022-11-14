#include <stdio.h>
#include <unistd.h>

int main()
{
    int n=fork();
    if(n>0)
    {
        printf("in parent\n");
    }
    else{
        sleep(10);
        printf("in child\n");
    }
}
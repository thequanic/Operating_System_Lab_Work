#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
    int n=fork();
    if(n>0)
    {
        sleep(30);
        printf("parent\n");
    }
    else
    {
        printf("child\n");
        exit(0);
    }
}
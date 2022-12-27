// Banker's Algorithm
#include <stdio.h>
int main()
{
	int n, m, i, j, k;

	printf("Enter number of process:");
    scanf("%d",&n);

    printf("Enter number of resources:");
    scanf("%d",&m);

	int alloc[n][m];

    for(i=0;i<n;i++)
    {
        printf("Enter number of each resource allocated to process P%d:",i);
        for(j=0;j<m;j++)
        {
            scanf("%d",&alloc[i][j]);
        }
    }

	int max[n][m];
    for(i=0;i<n;i++)
    {
        printf("Enter number of each resource required by process P%d gto complete:",i);
        for(j=0;j<m;j++)
        {
            scanf("%d",&max[i][j]);
        }
    }

	int avail[m];
    printf("Enter availability of each resource:");
    for(i=0;i<m;i++){scanf("%d",&avail[i]);}

	int f[n]; //it stores 1 for processes completed and 0 for non completed processes
	int ans[n], ind = 0;

	for (k = 0; k < n; k++) 
	{
		f[k] = 0;
	}

	int need[n][m];                  //calculating need of each process
	for (i = 0; i < n; i++) 
	{
		for (j = 0; j < m; j++)
			need[i][j] = max[i][j] - alloc[i][j];
	}
	int y = 0;

	for (k = 0; k < n; k++)  //for n times we will check if any process is reday to be completed
	{
		for (i = 0; i < n; i++) //we will check each process to test if ready to be completed
		{
			if (f[i] == 0)     //if process is not completed
			{
				int flag = 0;                 //flag is zero if process can be completed and 1 if process can not be completed
				for (j = 0; j < m; j++) 
				{
					if (need[i][j] > avail[j])      //check if avail of each resource fullfills need of process
					{
						flag = 1;	//if not set flag to 1 means process cannot comleted for now
						break;
					}
				}

				if (flag == 0)          //if flag==0
				{
					ans[ind++] = i;					//process is completed now, add it to ans array
					for (y = 0; y < m; y++)
						avail[y] += alloc[i][y];	//add each resource of this process to avail
					f[i] = 1;
				}
			}
		}
	}

	int flag = 1;
	
	for(int i=0;i<n;i++)
	{
		if(f[i]==0)	//if all process are not completed
		{
			flag=0;
			printf("The following system is not safe");
			break;
		}
	}
	
	if(flag==1)	//if all processes are completed 
	{
		printf("Following is the SAFE Sequence\n");

		for (i = 0; i < n - 1; i++)
			printf(" P%d ->", ans[i]);

		printf(" P%d", ans[n - 1]);
	}
	

	return (0);

}

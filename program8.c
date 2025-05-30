/*
    Program 8: Develop a C program to solve the sum of subsets problem using 
                Backtracking approach.
*/

#include <stdio.h>
#define MAX 10

int s[MAX], x[MAX], d;

void sumofsub(int p, int k, int r)
{
    int i;
    x[k]=1;
    if(p + s[k] == d)
    {
        for(i=1; i<=k; i++)
        if(x[i]==1)
            printf("%d ",s[i]);
        printf("\n");
    }

    else if (p + s[k] + s[k+1] <= d)
    {
        sumofsub(p + s[k], k+1, r - s[k]);
    }

    if((p + s[k+1] <= d) && (p + r - s[k] >= d))
    {
        x[k] = 0;
        sumofsub(p, k+1, r - s[k]);
    }
}

int main()
{
    int i,n,sum=0;
    printf("\nEnter n value: ");
    scanf("%d",&n);
    printf("\nEnter the set in increasing order: ");
    for(i=1;i<=n;i++)
        scanf("%d",&s[i]);
    for(i=1;i<=n;i++)
        sum = sum + s[i];
    printf("\nEnter the max subset value: ");
    scanf("%d",&d);
    if(sum < d || s[1] > d)
        printf("\nNo subsets possible.\n");
    else 
        sumofsub(0,1,sum);

    return 0;
}
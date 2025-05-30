/*
    Program 6: Develop a C program to solve 0/1 Knapsack problem using 
                Dynamic Programming.
*/

#include <stdio.h>

int max(int a, int b)
{
    return (a>b)?a:b;
}

int knapsack(int W, int wt[], int val[], int n)
{
    int i, w, K[n+1][W+1];
    for(i=0;i<=n;i++)
    {
        for(w=0;w<=W;w++)
        {
            if(i==0 || w==0)
                K[i][w]=0;
            else if(wt[i-1] <= w)
                K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]], K[i-1][w]);
            else
                K[i][w] = K[i-1][w];
        }
    }
    return K[n][W];
}

int main()
{
    int val[100], wt[100], W, n;
    printf("\nEnter the number of items: ");
    scanf("%d",&n);
    printf("\nEnter the values and weights of %d items:\n",n);
    for(int i=0; i<n; i++)
    {
        printf("Enter the weights and value for item %d: ",i+1);
        scanf("%d%d",&val[i],&wt[i]);
    }
    printf("Enter knapsack capacity: ");
    scanf("%d",&W);
    printf("\nMaximum value that can be obtained = %d\n", knapsack(W, wt, val, n));
}
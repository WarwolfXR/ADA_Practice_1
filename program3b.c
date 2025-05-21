/* 
    Program 3B: Develop a C program to solve the all pairs shortest path problem using Warshal's algorithm.
*/

#include <stdio.h>

void warshal(int p[][10], int n)
{
    int i,j,k;
    for(k=1;k<=n;k++)
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
        p[i][j] = p[i][j] || (p[i][k] && p[k][j]);
}

int main()
{
    int i,j,n,a[10][10];
    printf("\nEnter the number of nodes: ");
    scanf("%d",&n);
    printf("\nEnter the graph data:\n");
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
        scanf("%d",&a[i][j]);
    warshal(a,n);
    printf("\nShortest Path Matrix:\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}

/*
    OUTPUT:
    Enter the number of nodes: 4

Enter the graph data:
0 1 0 0
0 0 0 1
0 0 0 0 
1 0 1 0

Shortest Path Matrix:
1       1       1       1
1       1       1       1
0       0       0       0
1       1       1       1
*/
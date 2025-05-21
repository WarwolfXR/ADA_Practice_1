/* 
    Program 3A: Develop a C program to solve the all pairs shortest path problem using FLoyd's algorithm.
*/

#include <stdio.h>
#define INF 99

int min(int a, int b)
{
    return (a<b)?a:b;
}

void floyd(int p[][10], int n)
{
    int i,j,k;
    for(k=1;k<=n;k++)
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
        p[i][j] = min(p[i][j], p[i][k] + p[k][j]);
}

int main()
{
    int a[10][10], i, j, k, n;
    printf("\nEnter the number of nodes: ");
    scanf("%d",&n);
    printf("\nEnter the graph data:\n");
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
        scanf("%d",&a[i][j]);
    floyd(a,n);
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

/* OUTPUT:
    Enter the number of nodes: 4

Enter the graph data:
0 99 3 99
2 0 99 99
99 7 0 1
0 99 99 0

Shortest Path Matrix:
0       10      3       4
2       0       5       6
1       7       0       1
0       10      3       0
*/
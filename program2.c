/*  
    Program 2: Develop a C program to find the minimum cost spanning tree of an undirected connected graph using
                Prim's algorithm
*/

#include <stdio.h>

int ne=1, mincost=0;

int main()
{
    int i,j,k,n,a,u,b,v,visited[20],source,cost[20][20],min;
    printf("\nEnter the number of nodes: ");
    scanf("%d",&n);
    printf("\nEnter the cost matrix:\n");
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
        scanf("%d",&cost[i][j]);
    for(i=1;i<=n;i++)
        visited[i] = 0;
    printf("\nEnter the root node: ");
    scanf("%d",&source);
    visited[source] = 1;

    while (ne < n)
    {
        min = 999;
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (cost[i][j] < min)
                {
                    if (visited[i] == 1 && visited[j] == 0)
                    {
                        min = cost[i][j];
                        a = u = i;
                        b = v = j;
                    }
                }
            }
        }

        if(visited[u]==0 || visited[v]==0)
        {
            printf("\nEdge %d: (%d -> %d) = %d\n", ne++, a, b, min);
            mincost = mincost + min;
            visited[b] = 1;
        }
        cost[a][b] = cost[b][a] = 999;
    }
    printf("\nMinimum Cost = %d", mincost);

    return 0;
}

/* OUTPUT: 
    Enter the number of nodes: 5

Enter the cost matrix:
0 5 999 6 999
Enter the cost matrix:
0 5 999 6 999
0 5 999 6 999
5 0 1 3 999
999 1 0 4 6
6 3 4 0 2
999 999 6 2 0

Enter the root node: 1

Edge 1: (1 -> 2) = 5

Edge 2: (2 -> 3) = 1

Edge 3: (2 -> 4) = 3

Edge 4: (4 -> 5) = 2

Minimum Cost = 11
*/
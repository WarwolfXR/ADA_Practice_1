/*
    Program 1: Develop a C/C++ program to find the minimum cost spanning tree of a connect undirected graph using
                Kruskal's algorithm
*/

#include <stdio.h>

#define MAX 10
#define INF 99

int p[MAX], c[MAX][MAX], t[MAX][2];

int find(int v)
{
    while(p[v])
        v = p[v];
    return v;
}

void setunion(int i, int j)
{
    p[j] = i;
}

void kruskal(int n)
{
    int u,v,i,j,k,res1,res2,min,sum=0;

    for(k=1;k<n;k++)
    {
        min=INF;
        for(i=1;i<n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if (i==j) continue; //Skips self loops

                if(c[i][j] < min)
                {
                    u = find(i);
                    v = find(j);
                    
                    if(u != v)
                    {
                        res1 = i;
                        res2 = j;
                        min = c[i][j];
                    }
                }
            }
        }
        setunion(res1, find(res2));
        t[k][1] = res1;
        t[k][2] = res2;
        sum = sum + min;
    }

    printf("\nCost of spanning tree = %d",sum);
    printf("\nEdges of spanning tree:\n");
    for(i=1;i<n;i++)
        printf("%d -> %d\n",t[i][1],t[i][2]);
}

int main()
{
    int i,j,n;
    printf("\nEnter the number of nodes: ");
    scanf("%d",&n);

    printf("\nEnter the cost matrix: \n");
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
        scanf("%d",&c[i][j]);

    for(i=1;i<=n;i++)
        p[i] = 0;

    kruskal(n);

    return 0;
}

/*  OUTPUT:
        Enter the number of nodes: 5

Enter the cost matrix:
0 5 999 6 999
5 0 1 3 999
999 1 0 4 6
6 3 4 0 2
999 999 6 2 0

Cost of spanning tree = 11
Edges of spanning tree:
2 -> 3
4 -> 5
2 -> 4
1 -> 2
*/
/*
    Program 4: Develop a C program to find the shortest path from a given node
    in a connected graph using Dijkstra's algorithm.
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 10
#define INF 99

int d[MAX], p[MAX], visited[MAX];

void dijkstra(int a[MAX][MAX], int s, int n)
{
    int u,v,i,j,min;
    for(v=0;v<n;v++)
    {
        p[v]=-1;
        d[v]=INF;
        visited[v]=0;
    }
    d[s]=0;

    for(i=0;i<n;i++)
    {
        min = INF;
        for(j=0;j<n;j++)
        {
            if(d[j]<min && visited[j]==0)
            {
                min = d[j];
                u = j;
            }
        }
        visited[u] = 1;
        for(v=0;v<n;v++)
        {
            if((d[u] + a[u][v] < d[v]) && (u!=v) && (visited[v]==0))
            {
                d[v] = d[u] + a[u][v];
                p[v] = u;
            }
        }
    }
}

void path(int v, int s)
{
    if(p[v] != -1) path(p[v],s);
    if(v != s) printf("-> %d",v);
}

void display(int s, int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(i != s)
        {
            printf("%d",s);
            path(i,s);
        }
        if(i != s) printf("=%d",d[i]);
        printf("\n");
    }
}

int main()
{
    int i,j,n,a[MAX][MAX],s;
    printf("\nEnter the number of nodes: ");
    scanf("%d",&n);
    printf("\nEnter the graph data:\n");
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
        scanf("%d",&a[i][j]);
    printf("\nEnter the source vertex: ");
    scanf("%d",&s);
    dijkstra(a,s,n);
    printf("\nShortest path from vertex %d:\n",s);
    display(s,n);

    return 0;
}

/* OUTPUT:
    Enter the number of nodes: 5

Enter the graph data:
999 3 999 7 999
3 999 4 2 999
999 4 999 5 6
7 2 5 999 4
999 999 6 4 999

Enter the source vertex: 0

Shortest path from vertex 0:

0-> 1=99
0-> 2=99
0-> 3=99
0-> 4=99
PS C:\Coding Stuff\ADA_Practice_1> gcc program4.c
PS C:\Coding Stuff\ADA_Practice_1> ./a

Enter the number of nodes: 5

Enter the graph data:
999 3 999 7 999
3 999 4 2 999
999 4 999 5 6
7 2 5 999 4
999 999 6 4 999

Enter the source vertex: 0

Shortest path from vertex 0:

0-> 1=3
0-> 1-> 2=7
0-> 1-> 3=5
0-> 1-> 3-> 4=9
*/
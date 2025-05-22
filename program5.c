/*
    Program 5: Develop a C program to topologically order a directed, acyclic graph.
*/

#include <stdio.h>
#define MAX 10

int a[MAX][MAX], id[MAX], temp[MAX], k=0;

void sort(int a[MAX][MAX], int id[], int n)
{
    int i,j;
    for(i=1; i<=n; i++)
    {
        if(id[i]==0)
        {
            id[i]=-1;
            temp[++k]=i;
            for(j=1; j<=n; j++)
            {
                if(a[i][j]==1 && id[j]!=-1)
                    id[j]--;
            }
            i=0;
        }
    }
}

int main()
{
    int i,j,n;
    printf("\nEnter number of vertices: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++) id[i]=0;
    printf("\nEnter adjacency matrix:\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
            if(a[i][j]==1) id[j]++;
        }
    }
    sort(a, id, n);
    if(k!=n)
        printf("\nTopological ordering is not possible.");
    else
    {
        printf("\nTopological ordering is:");
        for(i=1;i<=n;i++)
            printf("%d\t",temp[i]);
    }

    return 0;
}

/* 
    OUTPUT:
    Enter number of vertices: 5

Enter adjacency matrix:
0 0 1 1 0
1 0 0 1 0
0 0 0 0 1
0 0 1 0 1
0 0 0 0 0

Topological ordering is:2       1       4       3       5
*/
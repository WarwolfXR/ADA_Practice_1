/*
    Program 10: Design and implement C/C++ Program to sort a given set of n integer elements
        using Merge Sort method and compute its time complexity.
        Run the program for varied values of n> 5000 and record the time taken to sort.
        Plot a graph of the time taken versus n.
        The elements can be read from a file or can be generated using the random number generator.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(long int arr[], long int low, long int mid, long int high)
{
    long int k=low, i=low, j=mid+1, temp[100000];
    while(i<=mid && j<=high)
    {
        if(arr[i]<=arr[j])
        {
            temp[k]=arr[i];
            i++;
            k++;
        }
        else
        {
            temp[k]=arr[j];
            j++;
            k++;
        }
    }
    while(i<=mid)
    {
        temp[k]=arr[i];
        i++;
        k++;
    }
    while(j<=high)
    {
        temp[k]=arr[j];
        j++;
        k++;
    }
    for(i=low;i<=high;i++)
        arr[i]=temp[i];
}

void mergesort(long int arr[], long int low, long int high)
{
    if(low<high)
    {
        long int mid = (low+high)/2;
        mergesort(arr,low,mid);
        mergesort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}

int main()
{
    long int n = 5000;
    double time[10];
    int it=0;
    printf("A-size,Merge:\n");
    while(it++<10)
    {
        long int a[n];
        for(int i=0;i<n;i++)
        {
            long int num = rand() % n+1;
            a[i] = num;
        }
        clock_t start, end;
        start = clock();
        mergesort(a,0,n-1);
        end=clock();
        time[it] = ((double)(end-start)) / CLOCKS_PER_SEC;
        printf("%li,%f\n",n,time[it]);
        n+=500;
    }
    return 0;
}
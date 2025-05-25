/*
    Program 7: Develop a C program to solve discrete Knapsack and continuous Knapsack
                using Greedy Approximation method.
*/

#include <stdio.h>

int main()
{
    int n, i, j, temp;
    float weight[50], profit[50], ratio[50], Total = 0, capacity;

    printf("\nEnter number of items: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("\nEnter weight and profit for item %d: ", i + 1);
        scanf("%f%f", &weight[i], &profit[i]);
    }

    printf("\nEnter capacity of Knapsack: ");
    scanf("%f", &capacity);

    for (i = 0; i < n; i++)
        ratio[i] = profit[i] / weight[i];

    for (i = 0; i < n; i++)
        for (j = i + 1; j < n; j++)
        {
            if (ratio[i] < ratio[j])
            {
                temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp;

                temp = profit[j];
                profit[j] = profit[i];
                profit[i] = temp;

                temp = weight[j];
                weight[j] = weight[i];
                weight[i] = temp;
            }
        }

    printf("\nKnapsack Problem using Greedy Approximation:\n");
    for (i = 0; i < n; i++)
    {
        if (weight[i] > capacity)
            break;
        else
        {
            Total = Total + profit[i];
            capacity = capacity - weight[i];
        }
    }

    if (i < n)
        Total = Total + (ratio[i] * capacity);
    printf("\nMaximum value is: %f\n", Total);

    return 0;
}

/*
    OUTPUT:
    Enter number of items: 3

    Enter weight and profit for item 1: 5 20

    Enter weight and profit for item 2: 10 25

    Enter weight and profit for item 3: 15 8

    Enter capacity of Knapsack: 16

    Knapsack Problem using Greedy Approximation:

    Maximum value is: 45.533333
*/
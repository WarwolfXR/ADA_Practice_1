#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int board[10], count = 1;

// Check if queen at row is safe
int place(int row, int col) {
    for (int i = 1; i < row; i++) {
        if (board[i] == col || abs(board[i] - col) == abs(i - row))
            return 0;
    }
    return 1;
}


// Print board
void printSolution(int n) {
    printf("Solution %d:\n", count++);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (board[i] == j)
                printf("Q ");
            else
                printf("- ");
        }
        printf("\n");
    }
    printf("\n");
}

// Backtracking to place queens
void queen(int row, int n) {
    for (int col = 1; col <= n; col++) {
        if (place(row, col)) {
            board[row] = col;
            if (row == n)
                printSolution(n);
            else
                queen(row + 1, n);
        }
    }
}



// Driver
int main() {
    int n;
    printf("Enter number of queens: ");
    scanf("%d", &n);
    queen(1, n);
    return 0;
}
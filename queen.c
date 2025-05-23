#include <stdio.h>
#include <stdlib.h>

int x[10];  // x[i] stores the column position of queen in row i
int count = 1;

void printBoard(int n) {
    printf("Solution %d:\n", count++);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (x[i] == j)
                printf("Q ");
            else
                printf("- ");
        }
        printf("\n");
    }
    printf("\n");
}

int isSafe(int row, int col) {
    for (int prev = 1; prev < row; prev++) {
        if (x[prev] == col || abs(x[prev] - col) == abs(prev - row))
            return 0;  // same column or diagonal attack
    }
    return 1;
}

void solveNQueens(int row, int n) {
    for (int col = 1; col <= n; col++) {
        if (isSafe(row, col)) {
            x[row] = col;
            if (row == n)
                printBoard(n);
            else
                solveNQueens(row + 1, n);
        }
    }
}

int main() {
    int n;
    printf("Enter the number of queens: ");
    scanf("%d", &n);

    solveNQueens(1, n);

    if (count == 1)
        printf("No solutions found.\n");

    return 0;
}

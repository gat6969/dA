#include <stdio.h>
#define INF 999

int min(int a, int b) {
    return (a < b) ? a : b;
}

void floyd(int n, int d[10][10]) {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

int main() {
    int n, a[10][10];
    
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    
    printf("\nEnter the adjacency matrix:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    
    floyd(n, a);
    
    printf("\nThe all-pairs shortest distance matrix is:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%5d", a[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}

#include <stdio.h>
#define INF 999

void prim(int cost[10][10], int n) {
    int visited[10] = {0}, minCost = 0;
    visited[0] = 1;

    printf("\nEdges in MST:\n");
    for (int count = 0; count < n - 1; count++) {
        int min = INF, u = -1, v = -1;
        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                for (int j = 0; j < n; j++) {
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }
        visited[v] = 1;
        printf("%d - %d : %d\n", u + 1, v + 1, min);
        minCost += min;
    }
    printf("Total Minimum Cost = %d\n", minCost);
}

int main() {
    int n, cost[10][10];
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter cost matrix (0 = no edge):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0) cost[i][j] = INF;
        }

    prim(cost, n);
    return 0;
}

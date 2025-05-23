#include <stdio.h>
#define MAX 10

void bfs(int a[MAX][MAX], int n, int src) {
    int q[MAX], f = 0, r = -1, v[MAX] = {0};
    v[src] = 1;
    q[++r] = src;
    printf("Reachable from node %d: ", src);
    while (f <= r) {
        int node = q[f++];
        printf("%d ", node);
        for (int i = 0; i < n; i++) {
            if (a[node][i] && !v[i]) {
                v[i] = 1;
                q[++r] = i;
            }
        }
    }
    printf("\n");
}

int main() {
    int n, src, a[MAX][MAX];
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    printf("Enter starting node: ");
    scanf("%d", &src);
    bfs(a, n, src);
    return 0;
}

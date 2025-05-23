#include <stdio.h>
#include <stdbool.h>

#define MAX 100

void dfs(int g[MAX][MAX], bool v[], int node, int n) {
    v[node] = true;
    for (int i = 0; i < n; i++)
        if (g[node][i] && !v[i])
            dfs(g, v, i, n);
}

bool is_connected(int g[MAX][MAX], int n) {
    bool v[MAX] = {0};
    dfs(g, v, 0, n);
    for (int i = 0; i < n; i++)
        if (!v[i]) return false;
    return true;
}

int main() {
    int n, e, g[MAX][MAX] = {0};
    printf("Enter nodes and edges: ");
    scanf("%d %d", &n, &e);
    printf("Enter edges (node1 node2):\n");
    for (int i = 0, u, v; i < e; i++) {
        scanf("%d %d", &u, &v);
        g[u][v] = g[v][u] = 1;
    }
    printf(is_connected(g, n) ? "Graph is connected.\n" : "Graph is not connected.\n");
    return 0;
}

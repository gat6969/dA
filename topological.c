#include <stdio.h>
#define MAX 10

int adj[MAX][MAX], visited[MAX], stack[MAX], top = -1;

void push(int v) { stack[++top] = v; }

void dfs(int v, int n) {
    visited[v] = 1;
    for (int i = 0; i < n; i++)
        if (adj[v][i] && !visited[i])
            dfs(i, n); 
    push(v);
}

void topologicalSort(int n) {
    for (int i = 0; i < n; i++) visited[i] = 0;
    for (int i = 0; i < n; i++)
        if (!visited[i]) dfs(i, n);
    printf("Topological Order: ");
    while (top >= 0) printf("%d ", stack[top--]);
    printf("\n");
}

int main() {
    int n, e, u, v;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &e);
    for (int i = 0; i < e; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }
    topologicalSort(n);
    return 0;
}

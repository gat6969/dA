#include <stdio.h>
#define INF 999  

void floydWarshall(int n, int graph[10][10]) {
    int i, j, k;
    for (k = 0; k < n; k++)       
        for (i = 0; i < n; i++)   
            for (j = 0; j < n; j++) 
                if (graph[i][k] + graph[k][j] < graph[i][j])
                    graph[i][j] = graph[i][k] + graph[k][j];
}

int main() {
    int n, i, j;
    int graph[10][10];

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (use %d for INF):\n", INF);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    floydWarshall(n, graph);

    printf("\nAll-pairs shortest distance matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (graph[i][j] == INF)
                printf(" INF ");
            else
                printf("%4d ", graph[i][j]);
        }
        printf("\n");
    }

    return 0;
}

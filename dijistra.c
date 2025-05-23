#include <stdio.h>
#define INFINITY 999

void dijkstra(int n, int cost[10][10], int source, int dist[], int visited[]) {
    int i, j, count, min, next;

    // Initialize distance and visited arrays
    for (i = 0; i < n; i++) {
        dist[i] = cost[source][i];
        visited[i] = 0;
    }

    dist[source] = 0;
    visited[source] = 1;

    // Find shortest path for all vertices
    for (count = 1; count < n - 1; count++) {
        min = INFINITY;
        next = -1;

        // Find the unvisited node with minimum distance
        for (i = 0; i < n; i++) {
            if (!visited[i] && dist[i] < min) {
                min = dist[i];
                next = i;
            }
        }

        visited[next] = 1;

        // Update the distances
        for (i = 0; i < n; i++) {
            if (!visited[i] && (min + cost[next][i] < dist[i])) {
                dist[i] = min + cost[next][i];
            }
        }
    }
}

int main() {
    int n, i, j, source;
    int cost[10][10], dist[10], visited[10];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix (use 999 for no path):\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    printf("Enter the source node (0 to %d): ", n - 1);
    scanf("%d", &source);

    dijkstra(n, cost, source, dist, visited);

    printf("\nShortest distances from node %d:\n", source);
    for (i = 0; i < n; i++) {
        printf("%d -> %d = %d\n", source, i, dist[i]);
    }

    return 0;
}

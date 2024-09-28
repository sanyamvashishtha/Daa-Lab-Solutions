#include <stdio.h>
#define INF 99999
#define MAX_N 20

// Function to perform Floyd-Warshall algorithm
void floydWarshall(int n, int dist[MAX_N][MAX_N]) {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

// Function to print the shortest distance matrix
void printSolution(int n, int dist[MAX_N][MAX_N]) {
    printf("The following matrix shows the shortest distances between all pairs of the vertices.\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] == INF) {
                printf("%5s", "INF");
            } else {
                printf("%5d", dist[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    int n, e;
    int dist[MAX_N][MAX_N];

    printf("Enter the number of vertices : ");
    scanf("%d", &n);
    printf("Enter the number of edges : ");
    scanf("%d", &e);

    // Initialize the distance matrix with INF and 0 for self-loops
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                dist[i][j] = 0;
            } else {
                dist[i][j] = INF;
            }
        }
    }

    // Input the edges
    for (int i = 0; i < e; i++) {
        int u, v, w;
        printf("Enter source : ");
        scanf("%d", &u);
        printf("Enter destination : ");
        scanf("%d", &v);
        printf("Enter weight : ");
        scanf("%d", &w);
        dist[u][v] = w;
    }

    // Apply Floyd-Warshall algorithm
    floydWarshall(n, dist);

    // Print the shortest distance matrix
    printSolution(n, dist);

    return 0;
}

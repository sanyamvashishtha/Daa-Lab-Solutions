#include<stdio.h>
#include<limits.h>

#define V_MAX 100
#define infinity INT_MAX

void Dijkstra(int a[V_MAX][V_MAX], int n, int source) {
    int dist[V_MAX], visited[V_MAX], i, j, minDist, nextNode;
    
    // Initialization
    for (i = 0; i < n; i++) {
        dist[i] = infinity;
        visited[i] = 0;
    }
    
    dist[source] = 0;

    // Algorithm core loop
    for (i = 0; i < n - 1; i++) {
        minDist = infinity;

        // Select the unvisited vertex with the smallest distance
        for (j = 0; j < n; j++) {
            if (!visited[j] && dist[j] < minDist) {
                minDist = dist[j];
                nextNode = j;
            }
        }

        visited[nextNode] = 1;

        // Update distance values of adjacent vertices of the selected vertex
        for (j = 0; j < n; j++) {
            if (!visited[j] && a[nextNode][j] && dist[nextNode] != infinity && dist[nextNode] + a[nextNode][j] < dist[j]) {
                dist[j] = dist[nextNode] + a[nextNode][j];
            }
        }
    }

    // Output results
    printf("Vertex \t\t Distance from Source\n");
    for (i = 0; i < n; i++) {
        printf("%d \t\t\t\t %d\n", i, dist[i]);
    }
}

int main() {
    int n, i, j, source;
    int a[V_MAX][V_MAX];

    // Input reading
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    
    source = 0;  // Considering the first vertex as the source node
    Dijkstra(a, n, source);

    return 0;
}

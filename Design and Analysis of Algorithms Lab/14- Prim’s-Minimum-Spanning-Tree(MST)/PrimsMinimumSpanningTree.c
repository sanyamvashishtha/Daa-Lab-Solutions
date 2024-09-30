#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

// Function to find the vertex with the smallest key value
int minKey(int key[], int mstSet[], int vertices) {
    int min = INT_MAX, min_index;
    
    for (int v = 0; v < vertices; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v], min_index = v;
        }
    }
    
    return min_index;
}

// Function to print the constructed MST stored in parent[]
void printMST(int parent[], int** graph, int vertices) {
    printf("Edge \tWeight\n");
    for (int i = 1; i < vertices; i++) {
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
    }
}

// Function to construct and print MST using Prim's algorithm
void primMST(int** graph, int vertices) {
    int* parent = (int*)malloc(vertices * sizeof(int));  // Array to store the constructed MST
    int* key = (int*)malloc(vertices * sizeof(int));     // Key values to pick minimum weight edge
    int* mstSet = (int*)malloc(vertices * sizeof(int));  // To represent the set of vertices included in MST

    // Initialize all keys as INFINITE and mstSet[] as false
    for (int i = 0; i < vertices; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    // Start from the first vertex
    key[0] = 0;     // Make key 0 so that this vertex is picked first
    parent[0] = -1; // First node is always the root of the MST

    // The MST will have V vertices
    for (int count = 0; count < vertices - 1; count++) {
        // Pick the minimum key vertex not yet included in MST
        int u = minKey(key, mstSet, vertices);

        // Add the picked vertex to the MST set
        mstSet[u] = 1;

        // Update key value and parent index of the adjacent vertices
        for (int v = 0; v < vertices; v++) {
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u, key[v] = graph[u][v];
            }
        }
    }

    // Print the constructed MST
    printMST(parent, graph, vertices);

    // Free dynamically allocated memory
    free(parent);
    free(key);
    free(mstSet);
}

int main() {
    int vertices;

    // Input number of vertices
    scanf("%d", &vertices);

    // Dynamically allocate memory for the adjacency matrix
    int** graph = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++) {
        graph[i] = (int*)malloc(vertices * sizeof(int));
    }

    // Input the graph as an adjacency matrix
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Compute and print the MST
    primMST(graph, vertices);

    // Free dynamically allocated memory for the graph
    for (int i = 0; i < vertices; i++) {
        free(graph[i]);
    }
    free(graph);

    return 0;
}

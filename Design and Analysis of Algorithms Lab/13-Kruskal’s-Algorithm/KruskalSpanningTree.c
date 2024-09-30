#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Structure to represent a subset for union-find
struct Subset {
    int parent;
    int rank;
};

// Function to find the subset of an element i (uses path compression)
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Function to unite two subsets using union by rank
void Union(struct Subset subsets[], int x, int y) {
    int rootX = find(subsets, x);
    int rootY = find(subsets, y);

    if (subsets[rootX].rank < subsets[rootY].rank) {
        subsets[rootX].parent = rootY;
    } else if (subsets[rootX].rank > subsets[rootY].rank) {
        subsets[rootY].parent = rootX;
    } else {
        subsets[rootY].parent = rootX;
        subsets[rootX].rank++;
    }
}

// Comparison function to sort edges by weight, then by src and dest if weights are equal
int compareEdges(const void* a, const void* b) {
    struct Edge* edgeA = (struct Edge*)a;
    struct Edge* edgeB = (struct Edge*)b;

    // First, compare by weight
    if (edgeA->weight != edgeB->weight)
        return edgeA->weight - edgeB->weight;

    // If weights are the same, compare by src
    if (edgeA->src != edgeB->src)
        return edgeA->src - edgeB->src;

    // If src is also the same, compare by dest
    return edgeA->dest - edgeB->dest;
}

// Kruskal's algorithm to find MST
void KruskalMST(struct Edge edges[], int V, int E) {
    struct Edge result[MAX];  // Array to store the result (MST)
    int resultIdx = 0;        // Index to track the result array
    int i, e;                 // Index variables

    // Sort edges by weight, then by src, then by dest
    qsort(edges, E, sizeof(struct Edge), compareEdges);

    // Allocate memory for creating V subsets
    struct Subset* subsets = (struct Subset*)malloc(V * sizeof(struct Subset));

    // Create V subsets with single elements
    for (i = 0; i < V; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    // Number of edges to be taken is equal to V-1
    i = 0;  // Index variable to pick the next edge
    while (resultIdx < V - 1 && i < E) {
        // Pick the smallest edge
        struct Edge nextEdge = edges[i++];

        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);

        // If the edge doesn't cause a cycle, include it in the result
        if (x != y) {
            result[resultIdx++] = nextEdge;
            Union(subsets, x, y);
        }
    }

    // Print the result with the exact formatting
    int minimumCost = 0;
    printf("The edges of Minimum Cost Spanning Tree are : \n");
    for (i = 0; i < resultIdx; i++) {
        printf("Edge cost from %d to %d : %d\n", result[i].src + 1, result[i].dest + 1, result[i].weight);
        minimumCost += result[i].weight;
    }
    printf("Minimum cost of spanning tree = %d\n", minimumCost);

    free(subsets);
}

int main() {
    int V, E;
    
    // Input number of vertices and edges
    printf("Enter the number of vertices : ");
    scanf("%d", &V);
    printf("Enter the number of edges : ");
    scanf("%d", &E);

    struct Edge edges[MAX];

    // Input all the edges
    for (int i = 0; i < E; i++) {
        int src, dest, weight;
        printf("Enter source : ");
        scanf("%d", &src);
        printf("Enter destination : ");
        scanf("%d", &dest);
        printf("Enter weight : ");
        scanf("%d", &weight);

        if (src <= 0 || dest <= 0 || src > V || dest > V) {
            printf("Invalid data.Try again.\n");
            i--;  // Retake input for the same edge
        } else {
            edges[i].src = src - 1;  // Adjust index to 0-based
            edges[i].dest = dest - 1;
            edges[i].weight = weight;
        }
    }

    // Call Kruskal's algorithm
    KruskalMST(edges, V, E);

    return 0;
}

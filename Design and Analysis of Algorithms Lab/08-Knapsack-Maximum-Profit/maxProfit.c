#include <stdio.h>

// Function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to solve the unbounded knapsack problem using dynamic programming
int knapsack(int W, int v[], int w[], int n) {
    int dp[W + 1];
    
    // Initialize all entries in dp array to 0
    for (int i = 0; i <= W; i++) {
        dp[i] = 0;
    }

    // Fill the dp array
    for (int i = 0; i < n; i++) {
        for (int j = w[i]; j <= W; j++) {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }

    // The maximum value that can be obtained with the given weight limit
    return dp[W];
}

int main() {
    int n, W;

    // Input the number of items
    scanf("%d", &n);

    int v[n], w[n];

    // Input the weights of the items
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
    }
    
    // Input the values of the items
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    // Input the size of the knapsack
    scanf("%d", &W);

    // Calculate the maximum value
    int maxValue = knapsack(W, v, w, n);

    // Output the result
    printf("%d\n", maxValue);

    return 0;
}

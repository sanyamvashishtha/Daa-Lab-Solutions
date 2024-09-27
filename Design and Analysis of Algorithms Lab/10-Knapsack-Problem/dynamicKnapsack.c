#include <stdio.h>
#include <stdlib.h>

// Function to get the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to solve the knapsack problem using dynamic programming
int knapsack(int w[], int p[], int n, int W) {
    int i, j;
    int dp[n + 1][W + 1];  // Create a DP table

    // Initialize the DP table with 0s
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= W; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (w[i - 1] <= j) {
                // Item can be included, choose the maximum value between including and excluding the item
                dp[i][j] = max(dp[i - 1][j], p[i - 1] + dp[i - 1][j - w[i - 1]]);
            } else {
                // Item cannot be included, just carry forward the value from the previous item
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][W];  // The bottom-right cell contains the result
}

int main() {
    int i, n;
    int W;
    int Max;

    printf("Enter the no. of items: ");
    scanf("%d", &n);

    int w[n];  // Array to store weights
    int p[n];  // Array to store prices

    printf("Enter the weight and price of all items\n");
    for (i = 0; i < n; i++) {
        scanf("%d%d", &w[i], &p[i]);
    }

    printf("Enter the capacity of knapsack: ");
    scanf("%d", &W);

    Max = knapsack(w, p, n, W);

    printf("The maximum value of items that can be put into knapsack is %d\n", Max);

    return 0;
}

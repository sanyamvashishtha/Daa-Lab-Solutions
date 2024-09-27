#include<stdio.h>

// Function to calculate the maximum profit for 0/1 Knapsack problem
int knapsack(int W, int weight[], int profit[], int n) {
    int dp[n+1][W+1]; // Create a table to store results of subproblems

    // Build the table dp[][] in bottom-up manner
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0; // Base case: no items or zero capacity
            }
            else if (weight[i-1] <= w) {
                dp[i][w] = (profit[i-1] + dp[i-1][w-weight[i-1]] > dp[i-1][w]) ? 
                            profit[i-1] + dp[i-1][w-weight[i-1]] : dp[i-1][w];
            }
            else {
                dp[i][w] = dp[i-1][w]; // Item cannot be included
            }
        }
    }
    return dp[n][W]; // The last cell contains the result (max profit)
}

int main() {
    int n, W;

    // Input number of items
    scanf("%d", &n);

    // Input capacity of knapsack
    scanf("%d", &W);

    int profit[n], weight[n];

    // Input profit values
    for (int i = 0; i < n; i++) {
        scanf("%d", &profit[i]);
    }

    // Input weight values
    for (int i = 0; i < n; i++) {
        scanf("%d", &weight[i]);
    }

    // Output the maximum total profit
    printf("%d\n", knapsack(W, weight, profit, n));

    return 0;
}

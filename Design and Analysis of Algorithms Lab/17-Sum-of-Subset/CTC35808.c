#include <stdio.h>
#include <stdlib.h>

void findSubsets(int* set, int n, int targetSum, int* currentSubset, int currentIndex, int subsetSize);
void printSubset(int* subset, int size);
int hasSolution = 0; // Flag to track if any solution exists

// Comparison function for sorting
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n, targetSum;

    // Input number of elements in the set
    scanf("%d", &n);
    int* set = (int*)malloc(n * sizeof(int));

    // Input the set of integers
    for (int i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }

    // Input the target sum
    scanf("%d", &targetSum);

    // Sort the set to maintain order
    qsort(set, n, sizeof(int), compare);

    int* currentSubset = (int*)malloc(n * sizeof(int)); // Temporary storage for current subset
    findSubsets(set, n, targetSum, currentSubset, 0, 0);

    // If no subsets were found
    if (!hasSolution) {
        printf("not possible\n");
    }

    // Free allocated memory
    free(set);
    free(currentSubset);

    return 0;
}

void findSubsets(int* set, int n, int targetSum, int* currentSubset, int currentIndex, int subsetSize) {
    // Base case: if the sum of the current subset equals the target sum
    if (targetSum == 0) {
        printSubset(currentSubset, subsetSize);
        hasSolution = 1; // Mark that at least one solution exists
        return;
    }

    // If we've reached the end of the set or if the targetSum is less than 0
    if (currentIndex >= n || targetSum < 0) {
        return;
    }

    // Include the current element
    currentSubset[subsetSize] = set[currentIndex];
    findSubsets(set, n, targetSum - set[currentIndex], currentSubset, currentIndex + 1, subsetSize + 1);

    // Exclude the current element and recurse
    findSubsets(set, n, targetSum, currentSubset, currentIndex + 1, subsetSize);
}

void printSubset(int* subset, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", subset[i]);
    }
    printf("\n");
}

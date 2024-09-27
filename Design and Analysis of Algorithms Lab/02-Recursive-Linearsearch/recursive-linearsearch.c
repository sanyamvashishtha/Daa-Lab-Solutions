#include <stdio.h>

// Recursive function for linear search
int recursiveLinearSearch(int arr[], int value, int index, int n) {
    if (index >= n) {
        return 0; // Return 0 if not found
    } else if (arr[index] == value) {
        return index + 1; // Return 1-based index when found
    } else {
        return recursiveLinearSearch(arr, value, index + 1, n); // Continue searching
    }
}

int main() {
    int n, value, pos;
    int arr[100];

    // Input number of elements
    printf("Enter n: ");
    scanf("%d", &n);

    // Input array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input element to search
    printf("Enter the element to search: ");
    scanf("%d", &value);

    // Perform recursive linear search
    pos = recursiveLinearSearch(arr, value, 0, n);

    // Output result
    if (pos != 0) {
        printf("Element found at pos %d ", pos);
    } else {
        printf("Element not found\n");
    }

    return 0;
}

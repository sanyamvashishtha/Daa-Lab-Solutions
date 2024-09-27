#include <stdio.h>

// Recursive function for binary search
int binarySearch(int arr[], int key, int low, int high) {
    if (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key) {
            return mid + 1; // Return 1-based index
        } else if (arr[mid] < key) {
            return binarySearch(arr, key, mid + 1, high);
        }
        return binarySearch(arr, key, low, mid - 1);
    }
    return -1;
}

int main() {
    int n, key;

    // Input number of elements
    printf("Enter n: ");
    scanf("%d", &n);

    // Input sorted array
    int arr[n];
    // printf("Enter the sorted array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input key to search
    printf("Enter the key element: ");
    scanf("%d", &key);

    // Perform binary search
    int result = binarySearch(arr, key, 0, n - 1);

    // Output result
    if (result == -1) {
        printf("The element is not found\n");
    } else {
        printf("The element is found at %d\n", result);
    }

    return 0;
}

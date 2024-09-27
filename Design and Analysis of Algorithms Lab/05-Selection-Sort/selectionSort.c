#include <stdio.h>

// Function to perform selection sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;  // Find the minimum element in the unsorted part
            }
        }
        // Swap the found minimum element with the first element of the unsorted part
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

int main() {
    int n;

    // Input array size
    printf("How many numbers u are going to enter?: ");
    scanf("%d", &n);

    int arr[n];

    // Input array elements
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Perform selection sort
    selectionSort(arr, n);

    // Output sorted array
    printf("Sorted elements are: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

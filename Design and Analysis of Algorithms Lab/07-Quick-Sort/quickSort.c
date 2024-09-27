#include <stdio.h>

// Function to perform quicksort
void quicksort(int num[], int first, int last) {
    int i, j, pivot, temp;

    if (first < last) {
        pivot = first;
        i = first;
        j = last;

        // Partitioning process
        while (i < j) {
            while (num[i] <= num[pivot] && i < last)
                i++;
            while (num[j] > num[pivot])
                j--;
            if (i < j) {
                temp = num[i];
                num[i] = num[j];
                num[j] = temp;
            }
        }

        // Swapping pivot to the correct position
        temp = num[pivot];
        num[pivot] = num[j];
        num[j] = temp;

        // Recursively sort the partitions
        quicksort(num, first, j - 1);
        quicksort(num, j + 1, last);
    }
}

int main() {
    int n, i;

    // Input the number of elements
    printf("Enter the no of elements: ");
    scanf("%d", &n);

    int o[n];

    // Input the elements
    printf("Enter numbers to be sorted: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &o[i]);
    }

    // Perform quicksort
    quicksort(o, 0, n - 1);

    // Output the sorted array
    printf("Sorted array is: ");
    for (i = 0; i < n; i++) {
        printf("%d ", o[i]);
    }
    printf("\n");

    return 0;
}

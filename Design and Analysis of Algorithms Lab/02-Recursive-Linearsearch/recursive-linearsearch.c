#include <stdio.h>
int recursiveLinearSearch(int arr[], int value, int index, int n) {
if (index >= n) {
return 0;
} else if (arr[index] == value) {
return index + 1;
} else {
return recursiveLinearSearch(arr, value, index + 1, n); // Continue searching
}
}
int main() {
int n, value, pos;
int arr[100];
printf("Enter n: ");
scanf("%d", &n);
for (int i = 0; i < n; i++) {
scanf("%d", &arr[i]);
}
printf("Enter the element to search: ");
scanf("%d", &value);
pos = recursiveLinearSearch(arr, value, 0, n);
if (pos != 0) {
printf("Element found at pos %d ", pos);
} else {
printf("Element not found\n");
}
return 0;
}

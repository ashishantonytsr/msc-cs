// Binary Search

#include <stdio.h>

int binary_search(int arr[], int size, int item) {
    int low = 0, high = size - 1, mid;

    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] == item)
            return mid + 1;
        else if (item < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

void main() {
    int arr[20], n, data;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter the array elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    printf("Enter the item to search: ");
    scanf("%d", &data);

    int pos = binary_search(arr, n, data);
    if (pos > -1)
        printf("Element found at location %d", pos);
    else
        printf("Element not found in the array");
}
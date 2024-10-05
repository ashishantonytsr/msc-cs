// Sparse matrix addition

#include <stdio.h>

void read_sparse_matrix(int arr[20], int r, int c) {
    int index = -1, element;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &element);
            if (element != 0) {
                arr[++index] = i;
                arr[++index] = j;
                arr[++index] = element;
            }
        }
    }
}

void add_sparse_matrix(int* arr1, int* arr2, int r, int c) {
    int i1 = 0, i2 = 0;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            int value = 0;
            if (arr1[i1] == i && arr1[i1 + 1] == j) {
                value += arr1[i1 + 2];
                i1 += 3;
            }
            if (arr2[i2] == i && arr2[i2 + 1] == j) {
                value += arr2[i2 + 2];
                i2 += 3;
            }
            printf("%d ", value);
        }
        printf("\n");
    }
}

void main() {
    int arr1[20], arr2[20], r, c;

    printf("Enter the number of rows and cols: ");
    scanf("%d %d", &r, &c);

    printf("Enter the first sparse matrix: \n");
    read_sparse_matrix(arr1, r, c);
    printf("Enter the second sparse matrix: \n");
    read_sparse_matrix(arr2, r, c);

    printf("The resultant sparse matrix is: \n");
    add_sparse_matrix(arr1, arr2, r, c);
}
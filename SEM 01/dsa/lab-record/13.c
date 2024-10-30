#include <stdio.h>
#define max 15

int heap[max], size = 0;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int i) {
    int min = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left] < heap[min])
        min = left;
    if (right < size && heap[right] < heap[min])
        min = right;
    if (min != i) {
        swap(&heap[min], &heap[i]);
        heapify(min);
    }
}

void insert(int key) {
    if (size >= max) {
        printf("Heap overflow.\n");
        return;
    }
    heap[size++] = key;

    for (int i = size - 1; i > 0; i = (i - 1) / 2)
        if (heap[i] < heap[(i - 1) / 2])
            swap(&heap[i], &heap[(i - 1) / 2]);
}

void deleteMin() {
    if (size <= 0) {
        printf("Heap underflow.\n");
        return;
    }
    heap[0] = heap[--size];
    heapify(0);
}

void display() {
    for (int i = 0; i < size; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

void main() {
    insert(5);
    insert(8);
    insert(3);
    insert(9);
    insert(7);
    insert(11);
    insert(12);
    insert(16);
    insert(6);

    display();
}

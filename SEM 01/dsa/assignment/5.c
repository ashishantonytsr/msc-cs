// Operations in Heap (Implemented as an Array)

#include <stdio.h>

# define max 15
int heap[max], size = 0;

void swap(int *a, int *b){
	/* swap function using call by reference method */
	int temp = *a;
	*a = *b;
	*b = temp;
}

void insert(int value){
	// heap overflow condition
	if (size >= max){
		printf("Heap Overflow\n");
		return;
	}

	// heap insertion
	heap[size++] = value;

	// fixing heap property if it is violated
	for (int i = size - 1; i > 0 && heap[(i - 1) / 2] < heap[i]; i = (i - 1) / 2)
		// if parent < current node, swap values
		swap(&heap[i], &heap[(i - 1) / 2]);
}

void heapify(){
	/* Traverse thru the heap array and check whether the elements following heap property */

	for(int i=0; i<size; i++) {
		int left = 2 * i + 1; // left child of current node
		int right = 2 * i + 2; // right child of current node
		int parent = (i - 1) / 2; // parent of current node

		if (heap[i] > heap[parent])
			swap(&heap[i], &heap[parent]);
		else if (left<size  && heap[i]<heap[left]) 
			swap(&heap[i], &heap[left]);
		else if (right<size && heap[i]>heap[right]) 
			swap(&heap[i], &heap[right]);
	}
}

void delete_at_index(int index){
	// index out of heap capacity
	if (index > max){
		printf("Invalid index\n");
		return;
	}

	// deleting last element
	if (index == size-1){
		size--;
		return;
	}

	// swapping the element at index with last element
	heap[index] = heap[size-1];
	size--;

	// to ensure heap property is maintained
	heapify();
}

void display(){
	for (int i=0; i<size; i++){
		printf("%d ", heap[i]);
	}
	printf("\n");
}

void main(){
	int x;
	printf("Enter the numbers into the heap (Enter 0 to stop): ");
	while(1) {
		scanf("%d", &x);
		if (x == 0)
			break;
		insert(x);
	}
	display();

	printf("Enter the index of node to be deleted: ");
	scanf("%d", &x);
	delete_at_index(x);
	display();
}

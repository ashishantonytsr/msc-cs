// Binary Search Trees on Arrays

#include <stdio.h>

// declare array and intialize first element as -1
int BST[100] = { -1 };

void _insert(int index, int item) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (BST[index] == -1) {
        BST[index] = item;

        // set left and right children as -1, simulating NULL
        BST[left] = BST[right] = -1;
        return;
    }

    if (item < BST[index])
        _insert(left, item);
    else
        _insert(right, item);
}

void _inorder_traversal(int index) {
    if (BST[index] == -1)
        return;
    _inorder_traversal(2 * index + 1);
    printf("%d ", BST[index]);
    _inorder_traversal(2 * index + 2);
}

/* 
 wrapper functions for _insert() and _inorder_traversal()
 used to initialize index as root index 
 */
void insert(int item) {
    _insert(0, item);
}

void inorder_traversal(){
    _inorder_traversal(0);
}


void main() {
    insert(12);
    insert(14);
    insert(11);
    insert(8);
    insert(10);
    insert(5);

    inorder_traversal();
}
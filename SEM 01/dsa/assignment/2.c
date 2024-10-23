// Inorder traversal in a BST

void inorder_traversal(struct node* root) {
    if (root != NULL) {
        inorder_traversal(root->left);
        printf("%d ", root->value);
        inorder_traversal(root->right);
    }
}



/* 
#include <stdio.h>

struct node {
    int value;
    struct node* left;
    struct node* right;
};

struct node* insert(struct node* root, int value) {
    if (root == NULL) {
        struct node* new_node = (struct node*)malloc(sizeof(struct node));
        new_node->value = value;
        new_node->left = new_node->right = NULL;
        return new_node;
    }
    if (value < root->value)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

void main() {
    struct node* root = NULL;

    root = insert(root, 5);
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 9);
    root = insert(root, 7);
    root = insert(root, 11);
    root = insert(root, 12);
    root = insert(root, 16);
    root = insert(root, 6);
    display(root);
    printf("\n");

    root = delete(root, 8);
    display(root);
}

*/
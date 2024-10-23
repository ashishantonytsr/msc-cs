// Operations in BST

#include <stdio.h>
#include <stdlib.h>

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

    // recursively traversing left & right subtrees
    if (value < root->value)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

void display(struct node* root) {
    if (root != NULL) {
        display(root->left);
        printf("%d ", root->value);
        display(root->right);
    }
}

struct node* delete(struct node* root, int value) {
    if (root == NULL) return root;

    // traversing the tree to find the node to be deleted
    if (value < root->value)
        root->left = delete(root->left, value);
    else if (value > root->value)
        root->right = delete(root->right, value);

    // found the node to be deleted
    else {

        // root has only right child
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }

        // root has only left child
        if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        // root has two children
        // ---
        // finding successor of root
        struct node* next = root->right;
        for (; next != NULL && next->left != NULL; next = next->left);

        // update root with value of successor node
        root->value = next->value;
        // delete successor node recursively
        root->right = delete(root->right, next->value);
    }
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

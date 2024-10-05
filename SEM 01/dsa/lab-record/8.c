// BST

#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node* left;
    struct node* right;
};

struct node* insert_node(struct node* root, int value) {
    if (root == NULL) {
        struct node* temp = (struct node*)malloc(sizeof(struct node));
        temp->value = value;
        temp->left = temp->right = NULL;
        return temp;
    }

    if (value < root->value)
        root->left = insert_node(root->left, value);
    else
        root->right = insert_node(root->right, value);

    return root;
}

struct node* delete_node(struct node* root, int value) {
    if (root == NULL) return;

    // Find the node to be deleted
    if (value < root->value)
        root->left = delete_node(root->left, value);
    else if (value > root->value)
        root->right = delete_node(root->right, value);

    else {
        // case 1: Node with one or zero children
        // return the non-null child node
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        // case 2: Node with two children
        // find min-value node in right subtree
        struct node* min_node = root;
        for (; min_node->left != NULL; min_node = min_node->left);

        // swap values of min-value node and root node
        int temp = min_node->value;
        min_node->value = root->value;
        root->value = temp;

        // remove the min-value node
        free(min_node);
    }
    return root;
}

// In-order tree traversal
void display(struct node* root) {
    if (root == NULL) return;
    display(root->left);
    printf("->%d ", root->value);
    display(root->right);
}

void main() {
    struct node* root = NULL;

    root = insert_node(root, 12);
    root = insert_node(root, 23);
    root = insert_node(root, 89);
    root = insert_node(root, 78);
    root = insert_node(root, 34);
    root = insert_node(root, 45);
    root = insert_node(root, 56);
    display(root);
    printf("\n");
    root = delete_node(root, 34);
    display(root);
    printf("\n");
    root = delete_node(root, 89);
    display(root);
    printf("\n");
    root = delete_node(root, 12);
    display(root);
    printf("\n");
    root = delete_node(root, 56);
    display(root);
    printf("\n");
}
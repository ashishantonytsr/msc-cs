// Recursive function to search in BST
void search(struct node* root, int value) {
    if (root == NULL) {
        printf("Item Not Found \n");
        return;
    }

    if (value == root->value)
        printf("Item Found \n");
    else if (value < root->value)
        search(root->left, value);
    else
        search(root->right, value);
}

// Non recursive function to search in BST
void search(struct node* root, int value) {
    struct node* temp = root;

    while (temp != NULL) {
        if (value == temp->value){
            printf("Item Found \n");
            return;
        }
        if (value < temp->value)
            temp = temp->left;
        else
            temp = temp->right;
    }
    printf("Item Not Found \n");
}
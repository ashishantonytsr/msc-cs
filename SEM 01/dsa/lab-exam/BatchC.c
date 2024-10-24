// TODO: Update question
/*
Batch 3: Lab-exam program
Problem:
    1. Store the elements of two given matrices of the same dimensions on two separate linked lists.
    2. Print the transpose of the matrices.
    3. Print the sum of the two matrices in matrix format
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int row; int col; int value;
    struct node* next;
}*head1 = NULL, * head2 = NULL;

struct node* insert(struct node* head, int row, int col, int value) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->row = row;
    new_node->col = col;
    new_node->value = value;
    new_node->next = NULL;

    if (head == NULL)
        head = new_node;
    else {
        struct node* temp = head;
        for (; temp->next != NULL; temp = temp->next);
        temp->next = new_node;
    }
    return head;
}

// TODO: find bug
struct node* matrix_sum(struct node* head1, struct node* head2) {
    for (struct node* i = head1; i != NULL; i = i->next) {
        for (struct node* j = head2; j != NULL; j = j->next) {
            if (i->row == j->row && i->col == j->col) {
                i->value += j->value;
            }
        }
    }
    return head1;
}

struct node* transpose(struct node* head) {
    for (struct node* temp = head; temp != NULL; temp = temp->next) {
        int t = temp->row;
        temp->row = temp->col;
        temp->col = t;
    }
    return head;
}

void display(struct node* head, int row) {
    for (int i = 0; i < row; i++) {
        for (struct node* temp = head; temp != NULL && temp->row == i; temp = temp->next) {
            printf("%d ", temp->value);
        }
        printf("\n");
    }
}

void main() {
    int r, c, element;

    printf("Enter the matrix dimension: ");
    scanf("%d %d", &r, &c);

    printf("Enter the elements of the first matrix: \n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &element);
            head1 = insert(head1, i, j, element);
        }
    }

    printf("Enter the elements of the second matrix: \n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &element);
            head2 = insert(head2, i, j, element);
        }
    }

    printf("Transpose of first matrix: \n");
    struct node* head1_t = transpose(head1);
    display(head1_t, c);

    printf("Transpose of second matrix: \n");
    struct node* head2_t = transpose(head2);
    display(head2_t, c);

    printf("Sum of matrices: \n");
    struct node* sum = matrix_sum(head1, head2);
    display(sum, r);
}
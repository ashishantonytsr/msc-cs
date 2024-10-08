/*
Batch 2: Lab-exam program
Problem:
    1. Create a linked list reading values from the user.
    2. Print the sum of elements of the list.
    3. Print the elements of the list in reverse (from the last to the first) with the help of a stack implemented as a linked list.
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node* next;
} *start = NULL, * end = NULL;

void insert(int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->value = data;
    temp->next = NULL;

    if (end == NULL)
        start = end = temp;
    else {
        end->next = temp;
        end = temp;
    }
}

int sum_of_nodes() {
    int sum = 0;
    for (struct node* temp = start; temp != NULL; temp = temp->next)
        sum += temp->value;
    return sum;
}

void reverse() {
    // creating stack pointer
    struct node* top = NULL;

    // traversing through the linked list
    for (struct node* temp = start; temp != NULL; temp = temp->next) {

        struct node* new_node = (struct node*)malloc(sizeof(struct node));
        new_node->value = temp->value;
        new_node->next = NULL;

        // insertion on stack
        if (top != NULL)
            new_node->next = top;
        top = new_node;
    }

    // printing stack
    printf("The reverse list is: ");
    for (struct node* temp = top; temp != NULL; temp = temp->next)
        printf("%d ", temp->value);
}

void display() {
    if (end == NULL)
        printf("List is empty.\n");
    else {
        printf("The list is: ");
        for (struct node* temp = start; temp != NULL; temp = temp->next)
            printf("%d ", temp->value);
        printf("\n");
    }
}

void main() {
    int n, element;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &element);
        insert(element);
    }

    display();
    printf("Sum: %d\n", sum_of_nodes());
    reverse();
}

/* 

Expected Output
---
Enter the number of elements: 6
Enter the elements 6 4 3 6 7 6
The list is: 6 4 3 6 7 6
Sum: 32
The reverse list is: 6 7 6 3 4 6

*/
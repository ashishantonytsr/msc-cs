/* 
Batch 1: Lab-exam program
Problem:
    1. Create a linked list reading values from the user.
    2. Search for an element input by the user.
    3. Delete all the instances of a given element from the list.
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

void delete(int data) {
    int is_found = 0;
    struct node* curr_node = start;
    struct node* prev_node = start;

    while (curr_node != NULL) {
        if (curr_node->value == data) {
            is_found = 1;
            if (curr_node == start)
                start = start->next;
            else
                prev_node->next = curr_node->next;
        }

        prev_node = curr_node;
        curr_node = curr_node->next;
    }

    if (is_found == 0) printf("Element not found.\n");
    else printf("Deleted.\n");
}

void search(int data) {
    for (struct node* temp = start; temp != NULL; temp = temp->next) {
        if (temp->value == data) {
            printf("Element found.\n");
            return;
        }
    }
    printf("Element not found.\n");
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
    for (int i=0; i<n; i++){
        scanf("%d", &element);
        insert(element);
    }

    display();

    printf("Enter the element to be searched for: ");
    scanf("%d", &element);
    search(element);

    printf("Enter the element to be deleted: ");
    scanf("%d", &element);
    delete(element);

    display();
}
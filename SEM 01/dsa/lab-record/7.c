// Queue using LL

#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node* next;
} *front = NULL, * rear = NULL;

void enqueue(int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->value = data;
    temp->next = NULL;

    if (rear == NULL)
        front = rear = temp;
    else {
        rear->next = temp;
        rear = temp;
    }
}

int dequeue() {
    if (front == NULL)
        return -1;

    int data = front->value;

    if (front == rear)
        front = rear = NULL;
    else
        front = front->next;
    return data;
}

void display() {
    if (front != NULL)
        for (struct node* temp = front; temp != NULL; temp = temp->next)
            printf("%d ", temp->value);
    else
        printf("Queue is empty\n");
}

void main() {
    int data, choice;

    while (1) {
        printf("\n1. Enqueue\t2. Dequeue\t3. Display\t4. Exit \nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the data: ");
            scanf("%d", &data);
            enqueue(data);
            break;

        case 2:
            (data = dequeue()) > -1 ?
                printf("Removed item: %d\n", data) :
                printf("Queue is empty\n");
            break;

        case 3:
            display();
            break;

        case 4:
            exit(0);
            break;

        default:
            printf("Invalid choice\n");
        }
    }
}
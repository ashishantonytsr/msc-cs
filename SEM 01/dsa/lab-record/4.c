// Queue using Arrays

#include <stdio.h>
#include <stdlib.h>

#define max 5
int queue[max], front = -1, rear = -1;

void enqueue(int data) {
    if (rear == max - 1)
        printf("Queue overflow\n");
    else {
        if (front == -1)
            ++front;
        queue[++rear] = data;
    }
}

void dequeue() {
    if (front == -1 || front > rear)
        printf("Queue underflow\n");
    else {
        printf("Removed item: %d\n", queue[front++]);
        if (front > rear)
            front = rear = -1;
    }
}

void display() {
    if (front = -1 || front > rear)
        printf("Queue is empty");
    else
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
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
            dequeue();
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
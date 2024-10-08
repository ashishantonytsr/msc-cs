// Stack using Arrays

#include <stdio.h>
#include <stdlib.h>

#define max 5
int stack[max], top = -1;

void push(int x) {
    if (top < max)
        stack[++top] = x;
    else
        printf("Stack overflow\n");
}

void pop() {
    if (top > -1)
        printf("Popped element is %d\n", stack[top--]);
    else
        printf("Stack underflow\n");
}

void display() {
    if (top <= -1)
        printf("Stack empty\n");
    else
        for (int i = top; i > -1; i--)
            printf("%d ", stack[i]);
}


void main() {
	int data, choice;

	while (1) {
		printf("\n1. Push\t2. Pop\t3. Display\t4. Exit \nEnter your choice: ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			printf("Enter the data: ");
			scanf("%d", &data);
			push(data);
			break;

		case 2:
			pop();
			break;

		case 3:
			display();
			break;

		case 4:
			exit(0);
			break;

		default:
			printf("Invalid input\n");
			break;
		}
	}
}

// Stack using LL

#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;
	struct node* next;
} *top = NULL;

void push(int data) {
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->value = data;
	temp->next = NULL;

	if (top != NULL)
		temp->next = top;
	top = temp;
}

int pop() {
	if (top == NULL)
		return -1;

	int data = top->value;
	top = top->next;
	return data;
}

void display() {
	if (top != NULL)
		for (struct node* temp = top; temp != NULL; temp = temp->next)
			printf("%d ", temp->value);
	else
		printf("Stack is empty\n");
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
			(data = pop()) > -1 ?
				printf("Removed item: %d\n", data) :
				printf("Stack is empty\n");
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
#include <stdio.h>
#include<conio.h>
#include <stdlib.h>

// Define the structure for the linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to push an element onto the stack (Insert at the beginning)
void push(struct Node** top, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *top; // Point new node to the current top
    *top = newNode; // Update the top to the new node
    printf("Inserted %d\n", data);
}

// Function to pop an element from the stack (Delete the top element)
int pop(struct Node** top) {
    struct Node* temp = *top;
    int poppedData;
    if (*top == NULL) {
	printf("Stack Underflow\n");
	return -1;
    }
    poppedData = temp->data;
    *top = (*top)->next; // Move top to the next node
    free(temp); // Free memory of the popped node
    printf("Popped %d\n", poppedData);
    return poppedData;
}

// Function to traverse the stack (Display elements)
void traverse(struct Node* top) {
    struct Node* temp = top;
    if (top == NULL) {
	printf("Stack is empty\n");
	return;
    }
    printf("Stack elements: ");
    while (temp != NULL) {
	printf("%d ", temp->data);
	temp = temp->next;
    }
    printf("\n");
}

void main() {
    struct Node* top = NULL; // Initialize the stack (linked list) as empty
    int choice, value;
    clrscr();
    while (1) {
	printf("\nMenu:\n");
	printf("1. Push\n");
	printf("2. Pop\n");
	printf("3. Traverse\n");
	printf("4. Exit\n");
	printf("Enter your choice: ");
	scanf("%d", &choice);

	switch (choice) {
	    case 1:
		printf("Enter the value to push: ");
		scanf("%d", &value);
		push(&top, value);
		break;
	    case 2:
		pop(&top);
		break;
	    case 3:
		traverse(top);
		break;
	    case 4:
		printf("Exiting...\n");
		exit(0); // Exit the program
	    default:
		printf("Invalid choice. Please try again.\n");
	}
    }

    getch();
}
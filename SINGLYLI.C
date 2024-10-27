#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
// Node structure for the singly linked stack
struct Node {
    int data;
    struct Node* next;
};

// Stack structure
struct Stack {
    struct Node* top;
};

// Function to create a new stack
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}

// Function to push an element onto the stack
void push(struct Stack* stack, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
    printf("Pushed %d onto the stack\n", data);
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    struct Node* temp = stack->top;
    int poppedData;
    if (stack->top == NULL) {
	printf("Stack is empty, cannot pop\n");
	return -1; // Indicate that the stack is empty
    }
    poppedData = temp->data;
    stack->top = stack->top->next;
    free(temp);
    printf("Popped %d from the stack\n", poppedData);
    return poppedData;
}

// Function to search for an element in the stack
int search(struct Stack* stack, int data) {
    struct Node* current = stack->top;
    int position = 0;

    while (current != NULL) {
	if (current->data == data) {
	    return position; // Return the position if found
	}
	current = current->next;
	position++;
    }
    return -1; // Indicate that the data was not found
}

// Function to display the contents of the stack
void display(struct Stack* stack) {
    struct Node* current = stack->top;
    if (current == NULL) {
	printf("Stack is empty\n");
	return;
    }
    printf("Stack contents (top to bottom): ");
    while (current != NULL) {
	printf("%d ", current->data);
	current = current->next;
    }
    printf("\n");
}

// Function to free the stack
void freeStack(struct Stack* stack) {
    struct Node* current = stack->top;
    struct Node* next;

    while (current != NULL) {
	next = current->next;
	free(current);
	current = next;
    }
    free(stack);
}

int main() {
    struct Stack* stack = createStack();
    int choice, data,position;
    clrscr();
    do {
	printf("\nMenu:\n");
	printf("1. Push\n");
	printf("2. Pop\n");
	printf("3. Search\n");
	printf("4. Display\n");
	printf("5. Exit\n");
	printf("Enter your choice: ");
	scanf("%d", &choice);

	switch (choice) {
	    case 1:
		printf("Enter data to push: ");
		scanf("%d", &data);
		push(stack, data);
		break;
	    case 2:
		pop(stack);
		break;
	    case 3:
		printf("Enter data to search: ");
		scanf("%d", &data);
		position = search(stack, data);
		if (position != -1) {
		    printf("Element %d found at position %d\n", data, position);
		} else {
		    printf("Element %d not found in the stack\n", data);
		}
		break;
	    case 4:
		display(stack);
		break;
	    case 5:
		printf("Exiting...\n");
		break;
	    default:
		printf("Invalid choice, please try again.\n");
	}
    } while (choice != 5);

    freeStack(stack);
    getch();
    return 0;
}

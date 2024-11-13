#include <stdio.h>
#include<conio.h>
#include <stdlib.h>

#define MAX 5 // Maximum size of the stack

// Stack structure
struct Stack {
    int arr[MAX];
    int top;
};

// Function to initialize the stack
void initStack(struct Stack* stack) {
    stack->top = -1; // Stack is empty initially
}

// Function to check if the stack is full
int isFull(struct Stack* stack) {
    return stack->top == MAX - 1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(struct Stack* stack, int value) {
    if (isFull(stack)) {
	printf("Stack Overflow! Cannot push %d onto the stack.\n", value);
    } else {
	stack->arr[++(stack->top)] = value;
	printf("Pushed %d onto the stack.\n", value);
    }
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
	printf("Stack Underflow! The stack is empty.\n");
	return -1;
    } else {
	int value = stack->arr[(stack->top)--];
	printf("Popped %d from the stack.\n", value);
	return value;
    }
}

// Function to search for an element in the stack
int search(struct Stack* stack, int value) {
   int i;
    for (i = stack->top; i >= 0; i--) {
	if (stack->arr[i] == value) {
	    return i; // Return the index of the element if found
	}
    }
    return -1; // Element not found
}

// Function to display all elements in the stack
void display(struct Stack* stack) {
   int i;
    if (isEmpty(stack)) {
	printf("Stack is empty.\n");
    } else {
	printf("Stack elements: ");
	for (i = stack->top; i >= 0; i--) {
	    printf("%d ", stack->arr[i]);
	}
	printf("\n");
    }
}

int main() {
    int choice, value, index,i;
    struct Stack stack;
    initStack(&stack);
    clrscr();

    // Menu for the user
    while (1) {
	printf("\nStack Operations Menu:\n");
	printf("1. Push\n");
	printf("2. Pop\n");
	printf("3. Search\n");
	printf("4. Display\n");
	printf("5. Exit\n");
	printf("Enter your choice: ");
	scanf("%d", &choice);

	switch (choice) {
	    case 1: // Push
		printf("Enter value to push: ");
		scanf("%d", &value);
		push(&stack, value);
		break;
	    case 2: // Pop
		pop(&stack);
		break;
	    case 3: // Search
		printf("Enter value to search: ");
		scanf("%d", &value);
		index = search(&stack, value);
		if (index != -1) {
		    printf("Element %d found at index %d.\n", value, index);
		} else {
		    printf("Element %d not found in the stack.\n", value);
		}
		break;
	    case 4: // Display
		display(&stack);
		break;
	    case 5: // Exit
		printf("Exiting program.\n");
		exit(0);
	    default:
		printf("Invalid choice! Please enter a valid option.\n");
	}
    }
    getch();
    return 0;
}

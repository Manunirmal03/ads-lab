#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// Define the structure for the linked list node
struct Node {
    int data;
    struct Node* next;
};

// Define the structure for the Queue
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Function to insert an element at the rear of the queue (Enqueue)
void enqueue(struct Queue* q, int data) {
    struct Node* newNode = createNode(data);

    if (q->rear == NULL) {  // If the queue is empty
        q->front = q->rear = newNode;
        printf("Enqueued %d\n", data);
        return;
    }

    q->rear->next = newNode; // Link the new node to the last node
    q->rear = newNode;       // Update the rear pointer to the new node
    printf("Enqueued %d\n", data);
}

// Function to remove an element from the front of the queue (Dequeue)
int dequeue(struct Queue* q) {
    struct Node* temp = q->front;
    int data;
    if (q->front == NULL) {
	printf("Queue Underflow\n");
        return -1;
    }

    data = temp->data;
    q->front = q->front->next; // Move the front pointer to the next node

    // If the front becomes NULL, also set rear to NULL (empty queue)
    if (q->front == NULL)
	q->rear = NULL;

    free(temp); // Free the memory of the dequeued node
    printf("Dequeued %d\n", data);
    return data;
}

// Function to traverse the queue and display elements
void traverse(struct Queue* q) {
    struct Node* temp = q->front;
    if (q->front == NULL) {
	printf("Queue is empty\n");
	return;
    }

    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to display menu and get user's choice
void displayMenu() {
    printf("\nQueue Operations:\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Traverse\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

void main() {
    struct Queue* q = createQueue(); // Create an empty queue
    int choice, value;
    clrscr();

    while (1) {
	displayMenu(); // Show the menu options
	scanf("%d", &choice);

	switch (choice) {
	    case 1:
		printf("Enter the value to enqueue: ");
		scanf("%d", &value);
		enqueue(q, value);
		break;
	    case 2:
		dequeue(q);
		break;
	    case 3:
		traverse(q);
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
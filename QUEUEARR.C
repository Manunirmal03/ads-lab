#include <stdio.h>
#include<conio.h>
#include <stdlib.h>

#define MAX 5  // Maximum size of the queue

// Queue structure
struct Queue {
    int arr[MAX];
    int front;
    int rear;
};

// Function to initialize the queue
void initQueue(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// Check if the queue is full
int isFull(struct Queue* q) {
    return q->rear == MAX - 1;
}

// Check if the queue is empty
int isEmpty(struct Queue* q) {
    return q->front == -1;
}

// Enqueue operation
void enqueue(struct Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;  // If queue is empty, set front to 0
    }
    q->rear++;
    q->arr[q->rear] = value;
    printf("Enqueued %d\n", value);
}

// Dequeue operation
int dequeue(struct Queue* q) {
    int dequeuedValue;
    if (isEmpty(q)) {
	printf("Queue is empty. Cannot dequeue.\n");
	return -1;  // Indicating that the queue is empty
    }
    dequeuedValue = q->arr[q->front];
    // If the queue has only one element left, reset the queue
    if (q->front == q->rear) {
	q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return dequeuedValue;
}

// Search for an element in the queue
int search(struct Queue* q, int value) {
   int i;
    if (isEmpty(q)) {
	printf("Queue is empty.\n");
	return -1;
    }
    for (i = q->front; i <= q->rear; i++) {
	if (q->arr[i] == value) {
	    return i;  // Return index of the element
	}
    }
    return -1;  // Element not found
}

// Display the elements of the queue
void display(struct Queue* q) {
   int i;
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue contents: ");
    for (i = q->front; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int choice, value, index;
    struct Queue q;
    initQueue(&q);
    clrscr();

    while (1) {
	printf("\nQueue Operations:\n");
	printf("1. Enqueue\n");
	printf("2. Dequeue\n");
	printf("3. Search\n");
	printf("4. Display\n");
	printf("5. Exit\n");
	printf("Enter your choice: ");
	scanf("%d", &choice);

	switch (choice) {
	    case 1:
		printf("Enter value to enqueue: ");
		scanf("%d", &value);
		enqueue(&q, value);
		break;
	    case 2:
		value = dequeue(&q);
		if (value != -1) {
		    printf("Dequeued value: %d\n", value);
		}
		break;
	    case 3:
		printf("Enter value to search: ");
		scanf("%d", &value);
		index = search(&q, value);
		if (index != -1) {
		    printf("Element %d found at index %d\n", value, index);
		} else {
		    printf("Element not found in the queue.\n");
		}
		break;
	    case 4:
		display(&q);
		break;
	    case 5:
		exit(0);
	    default:
		printf("Invalid choice. Try again.\n");
	}
    }
    getch();
    return 0;
}

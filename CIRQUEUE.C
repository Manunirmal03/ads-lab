#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#define MAX 5 // Maximum size of the queue

typedef struct {
    int items[MAX];
    int front;
    int rear;
} CircularQueue;

void initQueue(CircularQueue *q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(CircularQueue *q) {
    return (q->front == (q->rear + 1) % MAX);
}

int isEmpty(CircularQueue *q) {
    return (q->front == -1);
}

void enqueue(CircularQueue *q, int value) {
    if (isFull(q)) {
	printf("Queue is full. Cannot enqueue %d\n", value);
	return;
    }
    if (isEmpty(q)) {
	q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX;
    q->items[q->rear] = value;
    printf("Enqueued: %d\n", value);
}

int dequeue(CircularQueue *q) {
    int item = q->items[q->front];
    if (isEmpty(q)) {
	printf("Queue is empty. Cannot dequeue\n");
	return -1; // Indicates the queue is empty
    }

    if (q->front == q->rear) { // Queue has only one element
	q->front = -1;
	q->rear = -1;
    } else {
	q->front = (q->front + 1) % MAX;
    }
    printf("Dequeued: %d\n", item);
    return item;
}

int search(CircularQueue *q, int value) {
    int i = q->front;
    if (isEmpty(q)) {
	printf("Queue is empty. Cannot search\n");
	return -1; // Indicates the queue is empty
    }

    while (1) {
	if (q->items[i] == value) {
	    return i; // Return the index of the found element
	}
	if (i == q->rear) break; // Break if we've cycled through the queue
	i = (i + 1) % MAX;
    }
    return -1; // Value not found
}

void display(CircularQueue *q) {
    int i = q->front;
    if (isEmpty(q)) {
	printf("Queue is empty.\n");
	return;
    }
    printf("Queue elements: ");

    while (1) {
	printf("%d ", q->items[i]);
	if (i == q->rear) break;
	i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice, value, index;
    CircularQueue q;
    initQueue(&q);
    clrscr();
    do {
	printf("\nCircular Queue Operations:\n");
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
		dequeue(&q);
		break;
	    case 3:
		printf("Enter value to search: ");
		scanf("%d", &value);
		index = search(&q, value);
		if (index != -1) {
		    printf("Value %d found at index: %d\n", value, index);
		} else {
		    printf("Value %d not found in the queue.\n", value);
		}
		break;
	    case 4:
		display(&q);
		break;
	    case 5:
		printf("Exiting...\n");
		break;
	    default:
		printf("Invalid choice. Please try again.\n");
	}
    } while (choice != 5);
    getch();
    return 0;
}

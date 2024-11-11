#include <stdio.h>
#include<conio.h>
#define SIZE 5  // Define the maximum size of the queue

int queue[SIZE];
int front = -1, rear = -1;

// Function to check if the queue is full
int isFull() {
    return (front == (rear + 1) % SIZE);
}

// Function to check if the queue is empty
int isEmpty() {
    return (front == -1);
}

// Function to insert an element in the queue
void enqueue(int element) {
    if (isFull()) {
	printf("Queue is full!\n");
	return;
    }

    if (isEmpty()) {
	front = rear = 0;
    } else {
	rear = (rear + 1) % SIZE;
    }

    queue[rear] = element;
    printf("Inserted %d\n", element);
}

// Function to delete an element from the queue
void dequeue() {
    if (isEmpty()) {
	printf("Queue is empty!\n");
	return;
    }

    printf("Removed %d\n", queue[front]);

    if (front == rear) {
	// Queue is now empty after removing the last element
	front = rear = -1;
    } else {
	front = (front + 1) % SIZE;
    }
}

// Function to display the elements of the queue
void display() {
  int i;
    if (isEmpty()) {
	printf("Queue is empty!\n");
	return;
    }

    printf("Queue elements: ");
    i = front;
    while (1) {
	printf("%d ", queue[i]);
	if (i == rear)
	    break;
	i = (i + 1) % SIZE;
    }
    printf("\n");
}
// Function to search for an element in the queue
void search(int element) {
   int i;
    if (isEmpty()) {
        printf("Queue is empty! Cannot search.\n");
        return;
    }
    
    i = front;
    while (1) {
        if (queue[i] == element) {
            printf("Element %d found in the queue.\n", element);
            return;
        }
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    printf("Element %d not found in the queue.\n", element);
}


// Main function
int main() {
    int choice, value;
    clrscr();

    while (1) {
	printf("\nCircular Queue Operations:\n");
	printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Search\n5. Exit\n");
	printf("Enter your choice: ");
	scanf("%d", &choice);

	switch (choice) {
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Enter the value to search: ");
                scanf("%d", &value);
                search(value);
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
	
        }
    }
    getch();
}
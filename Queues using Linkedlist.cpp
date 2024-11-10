#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;
int MAX_SIZE;       // Maximum size of the queue set by the user
int currentSize = 0;

// Function to check if the queue is empty
int isEmpty() {
    return front == NULL;
}

// Function to check if the queue is full
int isFull() {
    return currentSize == MAX_SIZE;
}

// Function to enqueue an element to the queue
void enqueue(int value) {
    if (isFull()) {
        printf("Queue Overflow! Cannot enqueue %d\n", value);
        return;
    }
    
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;
    
    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    currentSize++;
    printf("Enqueued %d\n", value);
}

// Function to dequeue an element from the queue
void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow! Cannot dequeue\n");
        return;
    }
    
    struct Node* temp = front;
    printf("Dequeued %d\n", front->data);
    front = front->next;
    
    if (front == NULL) {
        rear = NULL;  // If the queue becomes empty, set rear to NULL as well
    }
    
    free(temp);
    currentSize--;
}

// Function to display the queue elements
void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    
    struct Node* temp = front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, value;
    
    printf("Enter the maximum size of the queue: ");
    scanf("%d", &MAX_SIZE);

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nChoose an option: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
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
                printf("Exiting...\n");
                // Free all remaining nodes before exit
                while (!isEmpty()) {
                    dequeue();
                }
                exit(0);
            default:
                printf("Invalid choice, try again.\n");
        }
    }
    return 0;
}


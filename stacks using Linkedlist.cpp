#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;  // Top of the stack
int MAX_SIZE;             // Maximum size of the stack
int currentSize = 0;      // Current size of the stack

// Function to check if the stack is empty
int isEmpty() {
    return top == NULL;
}

// Function to check if the stack is full
int isFull() {
    return currentSize == MAX_SIZE;
}

// Function to push an element onto the stack
void push(int value) {
    if (isFull()) {
        printf("Stack Overflow! Cannot push %d\n", value);
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    newNode->data = value;
    newNode->next = top;
    top = newNode;
    currentSize++;
    printf("Pushed %d\n", value);
}

// Function to pop an element from the stack
void pop() {
    if (isEmpty()) {
        printf("Stack Underflow! Cannot pop\n");
        return;
    }

    struct Node* temp = top;
    printf("Popped %d\n", top->data);
    top = top->next;
    free(temp);  // Free the memory of the popped node
    currentSize--;
}

// Function to display the stack elements
void display() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return;
    }

    struct Node* temp = top;
    printf("Stack: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to free all nodes in the stack (for cleanup before exit)
void freeStack() {
    struct Node* temp;
    while (top != NULL) {
        temp = top;
        top = top->next;
        free(temp);
    }
    currentSize = 0;
}

int main() {
    int choice, value;

    printf("Enter the maximum size of the stack: ");
    scanf("%d", &MAX_SIZE);

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\nChoose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                freeStack();  // Free all nodes in the stack before exit
                exit(0);
            default:
                printf("Invalid choice, try again.\n");
        }
    }
    return 0;
}



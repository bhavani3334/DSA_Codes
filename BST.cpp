#include <stdio.h>
#include <stdlib.h>

// Structure for BST Node
struct Node {
    int data;
    struct Node *llink, *rlink;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->llink = newNode->rlink = NULL;
    return newNode;
}

// Function to insert a node in BST
struct Node* insert(struct Node* root, int data, int* count, int max) {
    if (*count >= max) {
        printf("BST is full! Cannot insert more elements.\n");
        return root;
    }

    if (root == NULL) {
        (*count)++;
        return createNode(data);
    }

    if (data < root->data) {
        root->llink = insert(root->llink, data, count, max);
    } else if (data > root->data) {
        root->rlink = insert(root->rlink, data, count, max);
    } else {
        printf("Duplicate elements are not allowed in BST.\n");
    }

    return root;
}

// Function to search a node in BST
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }

    if (key < root->data) {
        return search(root->llink, key);
    }

    return search(root->rlink, key);
}

// Function to find the minimum value node
struct Node* findMin(struct Node* root) {
    while (root->llink != NULL) {
        root = root->llink;
    }
    return root;
}

// Function to delete a node in BST
struct Node* deleteNode(struct Node* root, int key, int* count) {
    if (root == NULL) {
        printf("Element not found in BST.\n");
        return root;
    }

    if (key < root->data) {
        root->llink = deleteNode(root->llink, key, count);
    } else if (key > root->data) {
        root->rlink = deleteNode(root->rlink, key, count);
    } else {
        // Node with one child or no child
        if (root->llink == NULL) {
            struct Node* temp = root->rlink;
            free(root);
            (*count)--;
            return temp;
        } else if (root->rlink == NULL) {
            struct Node* temp = root->llink;
            free(root);
            (*count)--;
            return temp;
        }

        // Node with two children
        struct Node* temp = findMin(root->rlink);
        root->data = temp->data;
        root->rlink = deleteNode(root->rlink, temp->data, count);
    }
    return root;
}

// Function for Inorder Traversal
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->llink);
        printf("%d ", root->data);
        inorder(root->rlink);
    }
}

// Function for Preorder Traversal
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->llink);
        preorder(root->rlink);
    }
}

// Function for Postorder Traversal
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->llink);
        postorder(root->rlink);
        printf("%d ", root->data);
    }
}

// Menu-driven program
int main() {
    struct Node* root = NULL;
    int maxElements, count = 0;
    int choice, value;

    // Ask the user for the maximum number of elements
    printf("Enter the maximum number of elements in the BST: ");
    scanf("%d", &maxElements);

    while (1) {
        printf("\nBinary Search Tree Operations:\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. Inorder Traversal\n");
        printf("5. Preorder Traversal\n");
        printf("6. Postorder Traversal\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value, &count, maxElements);
                break;

            case 2:
                printf("Enter value to search: ");
                scanf("%d", &value);
                if (search(root, value)) {
                    printf("%d is found in the BST.\n", value);
                } else {
                    printf("%d is not found in the BST.\n", value);
                }
                break;

            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value, &count);
                printf("%d is deleted from BST\n",value);
                break;

            case 4:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 5:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;

            case 6:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;

            case 7:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}


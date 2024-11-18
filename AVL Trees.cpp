#include <stdio.h>
#include <stdlib.h>

// Structure for an AVL Tree Node
struct Node {
    int data;
    struct Node* llink;
    struct Node* rlink;
    int height;
};

// Function to get the height of the tree
int height(struct Node* node) {
    return (node == NULL) ? 0 : node->height;
}

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->llink = newNode->rlink = NULL;
    newNode->height = 1; // New node is initially at height 1
    return newNode;
}

// Function to get the balance factor of a node
int getBalance(struct Node* node) {
    return (node == NULL) ? 0 : height(node->llink) - height(node->rlink);
}

// Right rotation
struct Node* rightRotate(struct Node* y) {
    struct Node* x = y->llink;
    struct Node* T2 = x->rlink;

    // Perform rotation
    x->rlink = y;
    y->llink = T2;

    // Update heights
    y->height = 1 + (height(y->llink) > height(y->rlink) ? height(y->llink) : height(y->rlink));
    x->height = 1 + (height(x->llink) > height(x->rlink) ? height(x->llink) : height(x->rlink));

    return x;
}

// Left rotation
struct Node* leftRotate(struct Node* x) {
    struct Node* y = x->rlink;
    struct Node* T2 = y->llink;

    // Perform rotation
    y->llink = x;
    x->rlink = T2;

    // Update heights
    x->height = 1 + (height(x->llink) > height(x->rlink) ? height(x->llink) : height(x->rlink));
    y->height = 1 + (height(y->llink) > height(y->rlink) ? height(y->llink) : height(y->rlink));

    return y;
}

// Insert a node into the AVL tree
struct Node* insert(struct Node* node, int data) {
    // Perform normal BST insertion
    if (node == NULL)
        return createNode(data);

    if (data < node->data)
        node->llink = insert(node->llink, data);
    else if (data > node->data)
        node->rlink = insert(node->rlink, data);
    else
        return node; // Duplicate keys not allowed

    // Update height of the current node
    node->height = 1 + (height(node->llink) > height(node->rlink) ? height(node->llink) : height(node->rlink));

    // Get the balance factor
    int balance = getBalance(node);

    // Balance the tree using rotations
    // Left Left Case
    if (balance > 1 && data < node->llink->data)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && data > node->rlink->data)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && data > node->llink->data) {
        node->llink = leftRotate(node->llink);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && data < node->rlink->data) {
        node->rlink = rightRotate(node->rlink);
        return leftRotate(node);
    }

    return node;
}

// Inorder traversal of the AVL tree
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->llink);
        printf("%d ", root->data);
        inorder(root->rlink);
    }
}

// Preorder traversal of the AVL tree
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->llink);
        preorder(root->rlink);
    }
}

// Postorder traversal of the AVL tree
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
    int choice, value, n, i;

    printf("Enter the number of nodes in the initial imbalanced tree: ");
    scanf("%d", &n);

    printf("Enter the node values:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value); // Insert each node into the AVL tree
    }

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert a node\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("Node inserted and tree balanced!\n");
                break;

            case 2:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 3:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;

            case 4:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;

            case 5:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}


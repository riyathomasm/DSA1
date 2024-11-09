#include <stdio.h>
#include <stdlib.h>

// Define a node in the doubly linked list
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
}Node;

// Function to create a new node with given value as data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to insert a node at the beginning
Node* insertAtBeginning(Node* head, int data) {
    Node* newNode = createNode(data);

    if (head == NULL) {
        return newNode;
    }

    newNode->next = head;
    head->prev = newNode;
    return newNode;
}

// Function to insert a node at the end
Node* insertAtEnd(Node* head, int data) {
    Node* newNode = createNode(data);

    if (head == NULL) {
        return newNode;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

// Function to insert a node at a specified position
Node* insertAtPosition(Node* head, int data, int position) {
    if (position < 1) {
        printf("Position should be >= 1.\n");
        return head;
    }

    if (position == 1) {
        return insertAtBeginning(head, data);
    }

    Node* newNode = createNode(data);
    Node* temp = head;
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position greater than the number of nodes.\n");
        free(newNode);
        return head;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    return head;
}

// Function to delete a node from the beginning
Node* deleteAtBeginning(Node* head) {
    if (head == NULL) {
        printf("The list is already empty.\n");
        return head;
    }

    Node* temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    free(temp);
    return head;
}

// Function to delete a node from the end
Node* deleteAtEnd(Node* head) {
    if (head == NULL) {
        printf("The list is already empty.\n");
        return head;
    }

    Node* temp = head;
    if (temp->next == NULL) {
        free(temp);
        return NULL;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->prev->next = NULL;
    free(temp);
    return head;
}

// Function to delete a node from a specified position
Node* deleteAtPosition(Node* head, int position) {
    if (head == NULL) {
        printf("The list is already empty.\n");
        return head;
    }

    if (position < 1) {
        printf("Position should be >= 1.\n");
        return head;
    }

    if (position == 1) {
        return deleteAtBeginning(head);
    }

    Node* temp = head;
    for (int i = 1; temp != NULL && i < position; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position is greater than the number of nodes.\n");
        return head;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    free(temp);
    return head;
}

// Function to print the list in forward direction
void printListForward(Node* head) {
    Node* temp = head;
    printf("Forward List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to print the list in reverse direction
void printListReverse(Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    printf("Reverse List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

// Main function with menu-driven interface
int main() {
    Node* head = NULL;
    int choice, data, position;

    while (1) {
        printf("\nDoubly Linked List Operations:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Position\n");
        printf("7. Print List Forward\n");
        printf("8. Print List Reverse\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                break;
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;
            case 3:
                printf("Enter position and data to insert: ");
                scanf("%d %d", &position, &data);
                head = insertAtPosition(head, data, position);
                break;
            case 4:
                head = deleteAtBeginning(head);
                break;
            case 5:
                head = deleteAtEnd(head);
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                head = deleteAtPosition(head, position);
                break;
            case 7:
                printListForward(head);
                break;
            case 8:
                printListReverse(head);
                break;
            case 9:
                // Free all nodes before exiting
                while (head != NULL) {
                    head = deleteAtBeginning(head);
                }
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}

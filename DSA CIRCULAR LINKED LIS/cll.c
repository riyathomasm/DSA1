#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the circular linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode; // Circular link
    return newNode;
}

// Function to insert a node at the beginning
struct Node* insertAtBeginning(struct Node* last, int data) {
    struct Node* newNode = createNode(data);

    if (last == NULL) {
        return newNode;
    }

    newNode->next = last->next;
    last->next = newNode;
    return last;
}

// Function to insert a node at the end
struct Node* insertAtEnd(struct Node* last, int data) {
    struct Node* newNode = createNode(data);

    if (last == NULL) {
        return newNode;
    }

    newNode->next = last->next;
    last->next = newNode;
    last = newNode;
    return last;
}

// Function to insert a node at a specific position
struct Node* insertAtPosition(struct Node* last, int position, int data) {
    if (position < 0) {
        printf("Invalid position\n");
        return last;
    }

    if (position == 0) {
        return insertAtBeginning(last, data);
    }

    struct Node* newNode = createNode(data);
    struct Node* curr = last->next;

    for (int i = 0; curr != last && i < position - 1; i++) {
        curr = curr->next;
    }

    if (curr == last && position > 1) {
        printf("Position out of range\n");
        free(newNode);
        return last;
    }

    newNode->next = curr->next;
    curr->next = newNode;
    if (curr == last) {
        last = newNode;
    }
    return last;
}

// Function to delete the node at the beginning
struct Node* deleteAtBeginning(struct Node* last) {
    if (last == NULL) {
        printf("List is empty\n");
        return last;
    }

    struct Node* head = last->next;
    if (head == last) {
        free(last);
        return NULL;
    }

    last->next = head->next;
    free(head);
    return last;
}

// Function to delete the last node
struct Node* deleteLastNode(struct Node* last) {
    if (last == NULL) {
        printf("List is empty, nothing to delete.\n");
        return NULL;
    }

    struct Node* head = last->next;
    if (head == last) {
        free(last);
        return NULL;
    }

    struct Node* curr = head;
    while (curr->next != last) {
        curr = curr->next;
    }

    curr->next = head;
    free(last);
    return curr;
}

// Function to delete a node at a specific position
struct Node* deleteAtPosition(struct Node* last, int position) {
    if (last == NULL) {
        printf("List is empty\n");
        return last;
    }

    if (position < 0) {
        printf("Invalid position\n");
        return last;
    }

    if (position == 0) {
        return deleteAtBeginning(last);
    }

    struct Node* curr = last->next;
    struct Node* prev = NULL;

    for (int i = 0; curr != last && i < position; i++) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == last && position > 1) {
        printf("Position out of range\n");
        return last;
    }

    if (prev != NULL) {
        prev->next = curr->next;
    } else {
        last->next = curr->next;
    }

    if (curr == last) {
        last = prev;
    }

    free(curr);
    return last;
}

// Function to print the circular linked list
void printList(struct Node* last) {
    if (last == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* head = last->next;
    struct Node* curr = head;

    do {
        printf("%d ", curr->data);
        curr = curr->next;
    } while (curr != head);

    printf("\n");
}

// Main function with menu-driven interface
int main() {
    struct Node* last = NULL;
    int choice, data, position;

    while (1) {
        printf("\nCircular Linked List Operations:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Position\n");
        printf("7. Print List\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                last = insertAtBeginning(last, data);
                break;
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                last = insertAtEnd(last, data);
                break;
            case 3:
                printf("Enter position and data to insert: ");
                scanf("%d %d", &position, &data);
                last = insertAtPosition(last, position, data);
                break;
            case 4:
                last = deleteAtBeginning(last);
                break;
            case 5:
                last = deleteLastNode(last);
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                last = deleteAtPosition(last, position);
                break;
            case 7:
                printList(last);
                break;
            case 8:
                // Free all nodes before exiting
                while (last != NULL) {
                    last = deleteAtBeginning(last);
                }
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}



#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node *next;
};

// Initialize the head of the list
struct Node *head = NULL;

// Function to create a new node
struct Node *newNode(int data) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a node at the beginning
void insertAtBeginning(int data) {
    struct Node *new_node = newNode(data);

    if (head == NULL) {
        head = new_node;
        new_node->next = head; // Make it circular
    } else {
        new_node->next = head;
        struct Node *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = new_node;
        head = new_node;
    }
}

// Function to insert a node at the end
void insertAtEnd(int data) {
    struct Node *new_node = newNode(data);

    if (head == NULL) {
        head = new_node;
        new_node->next = head; // Make it circular
    } else {
        struct Node *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->next = head;
    }
}

// Function to insert a node after a given node
void insertAfter(struct Node *prev_node, int data) {
    if (prev_node == NULL) {
        printf("Previous node cannot be NULL\n");
        return;
    }

    struct Node *new_node = newNode(data);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// Function to delete a node at the beginning
void deleteAtBeginning() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->next == head) { // Only one node
        free(head);
        head = NULL;
    } else {
        struct Node *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = head->next;
        free(head);
        head = head->next;
    }
}

// Function to delete a node at the end
void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->next == head) { // Only one node
        free(head);
        head = NULL;
    } else {
        struct Node *temp = head;
        while (temp->next->next != head) {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = head;
    }
}

// Function to delete a given node
void deleteNode(struct Node *del_node) {
    if (head == NULL || del_node == NULL) {
        printf("List is empty or node to be deleted is NULL\n");
        return;
    }

    if (head == del_node) {
        deleteAtBeginning();
    } else {
        struct Node *temp = head;
        while (temp->next != del_node) {
            temp = temp->next;
        }
        temp->next = del_node->next;
        free(del_node);
    }
}

// Function to traverse the circular linked list
void traverse() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("HEAD\n");
}

// Main function with menu-driven interface
int main() {
    int choice, data, position;
    struct Node *prev_node = NULL;

    while (1) {
        printf("\nCircular Linked List Operations:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert After a Given Node\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete a Given Node\n");
        printf("7. Traverse the List\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 3:
                if (head == NULL) {
                    printf("The list is empty, cannot insert after a node.\n");
                } else {
                    printf("Enter the value of the node to insert after: ");
                    scanf("%d", &data);
                    struct Node *temp = head;
                    while (temp->data != data && temp->next != head) {
                        temp = temp->next;
                    }
                    if (temp->data == data) {
                        printf("Enter data to insert: ");
                        scanf("%d", &data);
                        insertAfter(temp, data);
                    } else {
                        printf("Node with data %d not found.\n", data);
                    }
                }
                break;
            case 4:
                deleteAtBeginning();
                break;
            case 5:
                deleteAtEnd();
                break;
            case 6:
                if (head == NULL) {
                    printf("The list is empty.\n");
                } else {
                    printf("Enter the value of the node to delete: ");
                    scanf("%d", &data);
                    struct Node *temp = head;
                    while (temp->data != data && temp->next != head) {
                        temp = temp->next;
                    }
                    if (temp->data == data) {
                        deleteNode(temp);
                    } else {
                        printf("Node with data %d not found.\n", data);
                    }
                }
                break;
            case 7:
                traverse();
                break;
            case 8:
                // Free all nodes before exiting
                while (head != NULL) {
                    deleteAtBeginning();
                }
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}

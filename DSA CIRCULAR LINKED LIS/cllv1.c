#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

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

int main() {
    // Insert nodes
    insertAtBeginning(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAfter(head->next, 40);

    // Traverse the list
    printf("Circular Linked List:\n");
    traverse();

    // Delete nodes
    deleteAtBeginning();
    deleteAtEnd();
    deleteNode(head->next->next);

    // Traverse the list again
    printf("Circular Linked List after deletions:\n");
    traverse();

    return 0;
}
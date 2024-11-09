#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* new_node = createNode(data);
    new_node->next = head;
    return new_node;
}

struct Node* insertAtMiddle(struct Node* head, int position, int data) {
    struct Node* new_node = createNode(data);

    if (position < 0) {
        printf("Invalid position.\n");
        return head;
    }

    if (position == 0) {
        return insertAtBeginning(head, data);
    }

    struct Node* temp = head;
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Out of range.\n");
        free(new_node);
        return head;
    }

    new_node->next = temp->next;
    temp->next = new_node;
    return head;
}

struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* new_node = createNode(data);

    if (head == NULL) {
        return new_node;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
    return head;
}

void print(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data); // Print the data of the current node
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, position;

    while (1) {
        printf("1. Beginning\n");
        printf("2. Middle\n");
        printf("3. End\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                break;
            case 2:
                printf("Enter data and position: ");
                scanf("%d %d", &data, &position);
                head = insertAtMiddle(head, position, data);
                break;
            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;
            case 4:
                print(head);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createnode(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

struct Node* insertfront(struct Node* head, int data) {
    struct Node* new_node = createnode(data);
    new_node->next = head;
    return new_node;
}

struct Node* insertpos(struct Node* head, int data, int position) {
    if (position < 0) {
        printf("Invalid position\n");
        return head;
    }
    struct Node* new_node = createnode(data);
    if (position == 0) {
        return insertfront(head, data);
    }
    struct Node* temp = head;
    for (int i = 0 ; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of range\n");
        free(new_node);
        return head;
    }
    new_node->next = temp->next;
    temp->next = new_node;
    return head;
}

void Print(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, position;

    while (1) {
        printf("\n1. Insert at beginning\n");
        printf("2. Insert at position\n");
        printf("3. Print\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                head = insertfront(head, data);
                break;
            case 2:
                printf("Enter data and position: ");
                scanf("%d %d", &data, &position);
                head = insertpos(head, data, position);
                break;
            case 3:
                Print(head);
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}

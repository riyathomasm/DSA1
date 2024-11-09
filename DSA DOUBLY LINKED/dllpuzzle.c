#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* CreateNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

struct Node* InsertAtFirst(struct Node* head, int data) {
    struct Node* newNode = CreateNode(data);
    newNode->next = head;
    head->prev=newNode; //this line added
    return newNode;
}

struct Node* InsertAtEnd(struct Node* head, int data) {
    struct Node* newNode = CreateNode(data);
    if (head == NULL) {
        return newNode;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev=temp; //new line
    return head;
}

struct Node* InsertAtPosition(struct Node* head, int data, int position) {
    if (position < 1) {
        printf("Invalid position\n");
        return head;
    }
    struct Node* newNode = CreateNode(data);
    if (position == 1) {
        return InsertAtFirst(head, data);
    }
    struct Node* temp = head;
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of range\n");
        free(newNode);
        return head;
    }
    newNode->next = temp->next;
    newNode->prev=temp; //this new
    if(temp->next != NULL){ //this new
        temp->next->prev = newNode; //this new
    }
    temp->next = newNode;
    return head;
}

struct Node* DeleteFromFirst(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }
    struct Node* temp = head;
    head = head->next; //this changes temp from head
    if(head!=NULL){ //extra
        head->prev = NULL; //exra
    }
    free(temp); 
    return head;
}

struct Node* DeleteFromEnd(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    struct Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;
}

struct Node* DeleteAtPosition(struct Node* head, int position) {
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }
    if (position < 0) {
        printf("Invalid position\n");
        return head;
    }
    if (position == 0) {
        return DeleteFromFirst(head);
    }
    struct Node* temp = head;
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Position out of range\n");
        return head;
    }
    struct Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
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
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete from beginning\n");
        printf("5. Delete from end\n");
        printf("6. Delete at position\n");
        printf("7. Print\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                head = InsertAtFirst(head, data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                head = InsertAtEnd(head, data);
                break;
            case 3:
                printf("Enter data and position: ");
                scanf("%d %d", &data, &position);
                head = InsertAtPosition(head, data, position);
                break;
            case 4:
                head = DeleteFromFirst(head);
                break;
            case 5:
                head = DeleteFromEnd(head);
                break;
            case 6:
                printf("Enter position: ");
                scanf("%d", &position);
                head = DeleteAtPosition(head, position);
                break;
            case 7:
                Print(head);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;

}

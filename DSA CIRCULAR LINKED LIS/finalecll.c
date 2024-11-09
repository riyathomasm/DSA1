#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* INS_BEG(struct node *head, int val) {
    struct node *nn = (struct node *) malloc(sizeof(struct node));
    nn->data = val;

    if (head == NULL) {
        nn->next = nn;  // Point to itself if it's the only node
        return nn;
    }

    struct node *temp = head;
    while (temp->next != head)  // Find the last node
        temp = temp->next;

    nn->next = head;
    temp->next = nn;  // Make the last node point to the new head
    return nn;
}

struct node* INS_MID(struct node *head, int val, int pos) {
    struct node *nn = (struct node *) malloc(sizeof(struct node));
    nn->data = val;

    if (pos == 1) {
        return INS_BEG(head, val);  // Reuse the INS_BEG function
    }

    struct node *temp = head;
    for (int i = 1; i < pos - 1; i++) {
        temp = temp->next;
        if (temp == head) {
            printf("POSITION INVALID\n");
            return head;
        }
    }

    nn->next = temp->next;
    temp->next = nn;

    return head;
}

struct node* INS_END(struct node *head, int val) {
    struct node *nn = (struct node *) malloc(sizeof(struct node));
    nn->data = val;

    if (head == NULL) {
        nn->next = nn;  // Point to itself if it's the only node
        return nn;
    }

    struct node *temp = head;
    while (temp->next != head)  // Find the last node
        temp = temp->next;

    temp->next = nn;
    nn->next = head;  // New last node points to the head

    return head;
}

struct node* DEL_BEG(struct node *head) {
    if (head == NULL) {
        printf("LIST IS EMPTY\n");
        return head;
    }

    if (head->next == head) {  // Only one node in the list
        free(head);
        return NULL;
    }

    struct node *temp = head;
    while (temp->next != head)  // Find the last node
        temp = temp->next;

    struct node *toDelete = head;
    temp->next = head->next;  // Last node points to the new head
    head = head->next;
    free(toDelete);

    return head;
}

struct node* DEL_MID(struct node *head, int pos) {
    if (head == NULL) {
        printf("LIST IS EMPTY\n");
        return head;
    }

    if (pos == 1) {
        return DEL_BEG(head);  // Reuse the DEL_BEG function
    }

    struct node *temp = head;
    struct node *prev = NULL;
    for (int i = 1; i < pos; i++) {
        prev = temp;
        temp = temp->next;
        if (temp == head) {
            printf("POSITION INVALID\n");
            return head;
        }
    }

    prev->next = temp->next;
    free(temp);

    return head;
}

struct node* DEL_END(struct node *head) {
    if (head == NULL) {
        printf("LIST IS EMPTY\n");
        return head;
    }

    if (head->next == head) {  // Only one node in the list
        free(head);
        return NULL;
    }

    struct node *temp = head;
    while (temp->next->next != head)  // Find the second last node
        temp = temp->next;

    struct node *toDelete = temp->next;
    temp->next = head;  // Last node points to the head
    free(toDelete);

    return head;
}

void search(struct node *head, int val) {
    if (head == NULL) {
        printf("LIST IS EMPTY\n");
        return;
    }

    struct node *temp = head;
    int pos = 1;
    do {
        if (temp->data == val) {
            printf("VALUE %d FOUND AT POSITION %d\n", val, pos);
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);

    printf("VALUE %d NOT FOUND\n", val);
}

void traverse(struct node *head) {
    if (head == NULL) {
        printf("LIST IS EMPTY\n");
        return;
    }

    struct node *temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(HEAD)\n");
}

int main() {
    struct node *head = NULL;
    int choice, val, pos;

    do {
        printf("\nCHOOSE AN OPERATION:\n");
        printf("CHOICE 1: INSERTION AT THE BEGINNING\n");
        printf("CHOICE 2: INSERTION AT THE MIDDLE\n");
        printf("CHOICE 3: INSERTION AT THE END\n");
        printf("CHOICE 4: DELETION AT THE BEGINNING\n");
        printf("CHOICE 5: DELETION AT THE MIDDLE\n");
        printf("CHOICE 6: DELETION AT THE END\n");
        printf("CHOICE 7: SEARCHING\n");
        printf("CHOICE 8: TRAVERSAL\n");
        printf("CHOICE 9: EXIT\n");
        printf("ENTER YOUR CHOICE: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("ENTER VALUE: ");
                scanf("%d", &val);
                head = INS_BEG(head, val);
                break;
            case 2:
                printf("ENTER VALUE: ");
                scanf("%d", &val);
                printf("ENTER POSITION: ");
                scanf("%d", &pos);
                head = INS_MID(head, val, pos);
                break;
            case 3:
                printf("ENTER VALUE: ");
                scanf("%d", &val);
                head = INS_END(head, val);
                break;
            case 4:
                head = DEL_BEG(head);
                break;
            case 5:
                printf("ENTER POSITION: ");
                scanf("%d", &pos);
                head = DEL_MID(head, pos);
                break;
            case 6:
                head = DEL_END(head);
                break;
            case 7:
                printf("ENTER VALUE TO BE SEARCHED: ");
                scanf("%d", &val);
                search(head, val);
                break;
            case 8:
                traverse(head);
                break;
            case 9:
                printf("THANK YOU\n");
                break;
            default:
                printf("INVALID CHOICE!\n");
        }
    } while (choice != 9);

    return 0;
}

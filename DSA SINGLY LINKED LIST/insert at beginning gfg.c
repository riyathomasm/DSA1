#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

//to create a new node
struct Node* createnode(int new_data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    //We assign the data box of new node to the new data
    new_node->data = new_data;
    //we assign the pointer box of new node to NULL kyunki iska subsequent node nhi h
    new_node->next = NULL;
}

//to insert at beginning
//essentially the two parameters we use in this function
struct Node* insertAtFront(struct Node* head, int new_data){
    //this line creates a new node with create node function defined earlier with new data
        struct Node* new_node = createnode(new_data);
        new_node->next = head;
        return new_node;
}

void printlist(struct Node* head){
    //creates a new pointer named curr, this pointer is used to traverse linked list
    struct Node* curr = head;
    while(curr != NULL){
        printf("%d", curr->data);
        curr = curr->next;
        printf("/n");
    }
}

int main() {

    struct Node* head = createNode(2);
    head->next = createNode(3);
    head->next->next = createNode(4);
    head->next->next->next = createNode(5);

    printf("Original list: ");
    printList(head);

    int data = 1;
    head = insertAtFront(head, data);

    printf("After modifying: ");
    printList(head);

    return 0;
}

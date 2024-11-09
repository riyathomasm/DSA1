#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* next;
};

int main() {

    //creating head of linked list
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->value = 1;
    head->next = NULL;

    // Print the value of the head node
    printf("The value at head is %d\n", head->value);

    // If malloc is used we need to use free to deallocate to prevent memory leaks, basically preventing the other parts of program from accessing free pool
    free(head);

    return 0;
}
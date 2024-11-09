#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *start = NULL;

struct node *create_ll(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *insert_before(struct node *);
struct node *insert_after(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_node(struct node *);
struct node *delete_after(struct node *);
struct node *delete_list(struct node *);
struct node *sort_list(struct node *);

int main() {
    int option;
    do {
        printf("\n\n *****MAIN MENU *****");
        printf("\n 1: Create a list");
        printf("\n 2: Display the list");
        printf("\n 3: Add a node at the beginning");
        printf("\n 4: Add a node at the end");
        printf("\n 5: Add a node before a given node");
        printf("\n 6: Add a node after a given node");
        printf("\n 7: Delete a node from the beginning");
        printf("\n 8: Delete a node from the end");
        printf("\n 9: Delete a given node");
        printf("\n 10: Delete a node after a given node");
        printf("\n 11: Delete the entire list");
        printf("\n 12: Sort the list");
        printf("\n 13: EXIT");
        printf("\n\n Enter your option : ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                start = create_ll(start);
                printf("\n LINKED LIST CREATED");
                break;
            case 2:
                start = display(start);
                break;
            case 3:
                start = insert_beg(start);
                break;
            case 4:
                start = insert_end(start);
                break;
            case 5:
                start = insert_before(start);
                break;
            case 6:
                start = insert_after(start);
                break;
            case 7:
                start = delete_beg(start);
                break;
            case 8:
                start = delete_end(start);
                break;
            case 9:
                start = delete_node(start);
                break;
            case 10:
                start = delete_after(start);
                break;
            case 11:
                start = delete_list(start);
                printf("\n LINKED LIST DELETED");
                break;
            case 12:
                start = sort_list(start);
                break;
        }
    } while(option != 13);

    return 0;
}

struct node *create_ll(struct node *start) {
    struct node *new_node, *ptr;
    int num;
    printf("\n Enter -1 to end");
    printf("\n Enter the data : ");
    scanf("%d", &num);

    while(num != -1) {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = num;
        new_node->next = NULL;

        if(start == NULL) {
            start = new_node;
        } else {
            ptr = start;
            while(ptr->next != NULL)
                ptr = ptr->next;
            ptr->next = new_node;
        }

        printf("\n Enter the data : ");
        scanf("%d", &num);
    }
    return start;
}

struct node *display(struct node *start) {
    struct node *ptr = start;
    while(ptr != NULL) {
        printf("\t %d", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
    return start;
}

struct node *insert_beg(struct node *start) {
    struct node *new_node;
    int num;
    printf("\n Enter the data : ");
    scanf("%d", &num);

    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->next = start;
    start = new_node;

    return start;
}

struct node *insert_end(struct node *start) {
    struct node *ptr, *new_node;
    int num;
    printf("\n Enter the data : ");
    scanf("%d", &num);

    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->next = NULL;

    if(start == NULL) {
        start = new_node;
    } else {
        ptr = start;
        while(ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = new_node;
    }

    return start;
}

struct node *insert_before(struct node *start) {
    struct node *new_node, *ptr, *preptr;
    int num, val;
    printf("\n Enter the data : ");
    scanf("%d", &num);
    printf("\n Enter the value before which the data has to be inserted : ");
    scanf("%d", &val);

    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;

    ptr = start;
    preptr = NULL;

    if (ptr != NULL && ptr->data == val) {
        new_node->next = start;
        start = new_node;
        return start;
    }

    while(ptr != NULL && ptr->data != val) {
        preptr = ptr;
        ptr = ptr->next;
    }

    if(ptr != NULL) {
        preptr->next = new_node;
        new_node->next = ptr;
    } else {
        printf("\n Node with value %d not found", val);
        free(new_node);
    }

    return start;
}

struct node *insert_after(struct node *start) {
    struct node *new_node, *ptr;
    int num, val;
    printf("\n Enter the data : ");
    scanf("%d", &num);
    printf("\n Enter the value after which the data has to be inserted : ");
    scanf("%d", &val);

    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;

    ptr = start;

    while(ptr != NULL && ptr->data != val) {
        ptr = ptr->next;
    }

    if(ptr != NULL) {
        new_node->next = ptr->next;
        ptr->next = new_node;
    } else {
        printf("\n Node with value %d not found", val);
        free(new_node);
    }

    return start;
}

struct node *delete_beg(struct node *start) {
    struct node *ptr;
    if(start == NULL) {
        printf("\n List is already empty");
        return start;
    }

    ptr = start;
    start = start->next;
    free(ptr);

    return start;
}

struct node *delete_end(struct node *start) {
    struct node *ptr, *preptr;
    if(start == NULL) {
        printf("\n List is already empty");
        return start;
    }

    ptr = start;
    if(ptr->next == NULL) {
        free(ptr);
        return NULL;
    }

    while(ptr->next != NULL) {
        preptr = ptr;
        ptr = ptr->next;
    }

    preptr->next = NULL;
    free(ptr);

    return start;
}

struct node *delete_node(struct node *start) {
    struct node *ptr, *preptr;
    int val;
    printf("\n Enter the value of the node which has to be deleted : ");
    scanf("%d", &val);

    ptr = start;
    if(ptr != NULL && ptr->data == val) {
        start = delete_beg(start);
        return start;
    }

    while(ptr != NULL && ptr->data != val) {
        preptr = ptr;
        ptr = ptr->next;
    }

    if(ptr != NULL) {
        preptr->next = ptr->next;
        free(ptr);
    } else {
        printf("\n Node with value %d not found", val);
    }

    return start;
}

struct node *delete_after(struct node *start) {
    struct node *ptr, *preptr;
    int val;
    printf("\n Enter the value after which the node has to be deleted : ");
    scanf("%d", &val);

    ptr = start;
    while(ptr != NULL && ptr->data != val) {
        ptr = ptr->next;
    }

    if(ptr != NULL && ptr->next != NULL) {
        preptr = ptr->next;
        ptr->next = preptr->next;
        free(preptr);
    } else {
        printf("\n Node with value %d not found or no node to delete", val);
    }

    return start;
}

struct node *delete_list(struct node *start) {
    struct node *ptr;
    while(start != NULL) {
        ptr = start;
        start = start->next;
        free(ptr);
    }
    return start;
}

struct node *sort_list(struct node *start) {
    struct node *ptr1, *ptr2;
    int temp;
    if(start == NULL) {
        return start;
    }

    for(ptr1 = start; ptr1->next != NULL; ptr1 = ptr1->next) {
        for(ptr2 = ptr1->next; ptr2 != NULL; ptr2 = ptr2->next) {
            if(ptr1->data > ptr2->data) {
                temp = ptr1->data;
                ptr1->data = ptr2->data;
                ptr2->data = temp;
            }
        }
    }

    return start;
}

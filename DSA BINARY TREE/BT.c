#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* lc;
    struct Node* rc;

};

struct Node* createnode(int data){
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->lc = NULL;
    newnode->rc = NULL;
    return newnode;
}

struct Node* insert(struct Node* root, int data){
    if(root == NULL){
        root = createnode(data);
    }
    else if(data<=root->data){
        root -> lc = insert (root -> lc, data);
    }
    else{
        root -> rc = insert(root-> rc, data);
    }
    return root;
}

void inordertraversal(struct Node* root){
    if(root != NULL){
        inordertraversal(root ->lc);
        printf(" %d ", root->data);
        inordertraversal(root ->rc);
    }
}

int main(){
    struct Node* root = NULL;
    root = insert(root, 50);
    insert(root, 20);
    insert(root, 22);

    printf(" %d ");

    inordertraversal(root);

    printf("\n");

    return 0;
}
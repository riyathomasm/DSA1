#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* lc;
    struct node* rc;
};

struct node* newnode(int x){
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp -> data = x;
    temp -> lc = NULL;
    temp -> rc = NULL;
    return temp;
}

struct node* search(struct node* root, int x){
    if(root == NULL || root -> data == x){
        return root;
    }else if(x>root -> data){
        return search (root -> rc, x);
    }else{
        return search (root -> lc, x);
    }
}

struct node* insert(struct node* root, int x){
    if(root == NULL){
        return newnode(x);
    }else if(x>root->data){
        root -> rc = insert(root ->rc, x);
    }else{
        root -> lc = insert(root -> lc, x);
    }

    return root;
}

void inorder(struct node* root){
    if(root != NULL){
        inorder(root -> lc);
        printf(" %d ", root -> data);
        inorder(root-> rc);
    }
}


int main(){
    struct node* root = NULL;  // Initialize root to NULL
    root = newnode(20);        // Create the root node with data 20
    insert(root, 4);
    insert(root, 22);
    insert(root, 34);

    printf("Inorder traversal of the binary search tree: ");
    inorder(root);
    printf("\n");

    return 0;
}

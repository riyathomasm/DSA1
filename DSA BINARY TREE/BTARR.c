#include <stdio.h>

#define MAX_SIZE 100  // Maximum size of the array representing the tree

// Function to insert an element into the tree
void insert(int tree[], int* size, int value) {
    if (*size >= MAX_SIZE) {
        printf("Tree is full.\n");
        return;
    }
    tree[*size] = value;  // Insert at the next available position
    (*size)++;
}

// Inorder traversal of the binary tree represented by an array
void inorder(int tree[], int size, int index) {
    if (index >= size) {
        return;
    }
    inorder(tree, size, 2 * index + 1);    // Visit left child
    printf("%d ", tree[index]);            // Visit current node
    inorder(tree, size, 2 * index + 2);    // Visit right child
}

int main() {
    int tree[MAX_SIZE];   // Array to hold tree elements
    int size = 0;         // Current number of elements in the tree

    // Insert elements into the binary tree
    insert(tree, &size, 10);
    insert(tree, &size, 5);
    insert(tree, &size, 15);
    insert(tree, &size, 3);
    insert(tree, &size, 7);
    insert(tree, &size, 12);
    insert(tree, &size, 18);

    // Perform inorder traversal
    printf("Inorder traversal of the binary tree: ");
    inorder(tree, size, 0);
    printf("\n");

    return 0;
}

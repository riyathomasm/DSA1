#include <stdio.h>

#define MAX_SIZE 100

// Array to hold the BST elements; initialize all elements to -1
int tree[MAX_SIZE];

// Function to insert a value into the array-based BST
void insert(int index, int value) {
    if (index >= MAX_SIZE) {
        printf("Array is full. Cannot insert more elements.\n");
        return;
    }

    if (tree[index] == -1) {  // If the position is empty, place the value
        tree[index] = value;
    } else if (value < tree[index]) {
        insert(2 * index + 1, value);  // Go to the left child
    } else if (value > tree[index]) {
        insert(2 * index + 2, value);  // Go to the right child
    }
}

// Inorder traversal of the BST represented by an array
void inorder(int index) {
    if (index >= MAX_SIZE || tree[index] == -1) {
        return;
    }
    inorder(2 * index + 1);           // Visit left child
    printf("%d ", tree[index]);       // Visit current node
    inorder(2 * index + 2);           // Visit right child
}

int main() {
    // Initialize the tree array to -1 (indicating empty positions)
    for (int i = 0; i < MAX_SIZE; i++) {
        tree[i] = -1;
    }

    // Insert elements into the BST
    insert(0, 50);  // Root node
    insert(0, 30);
    insert(0, 70);
    insert(0, 20);
    insert(0, 20);
    insert(0, 60);
    insert(0, 80);

    // Perform inorder traversal
    printf("Inorder traversal of the binary search tree: ");
    inorder(0);
    printf("\n");

    return 0;
}

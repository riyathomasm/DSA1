#include <stdio.h>

#define MAX_SIZE 100

int heap[MAX_SIZE];
int size = 0;

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify up - Used after insertion to maintain the Min-Heap property
void heapifyUp(int index) {
    if (index && heap[(index - 1) / 2] > heap[index]) {
        // Swap if the parent is greater than the current node
        swap(&heap[(index - 1) / 2], &heap[index]);
        // Recursively heapify up the parent node
        heapifyUp((index - 1) / 2);
    }
}

// Insert a new element in the Min-Heap
void insert(int value) {
    if (size >= MAX_SIZE) {
        printf("Heap is full\n");
        return;
    }
    heap[size] = value;  // Insert the new value at the end of the heap
    heapifyUp(size);     // Heapify up to maintain the Min-Heap property
    size++;              // Increase the size of the heap
}

// Heapify down - Used after deletion to maintain the Min-Heap property
void heapifyDown(int index) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int smallest = index;

    // Find the smallest among root, left child, and right child
    if (left < size && heap[left] < heap[smallest]) {
        smallest = left;
    }
    if (right < size && heap[right] < heap[smallest]) {
        smallest = right;
    }

    // Swap and continue heapifying if root is not the smallest
    if (smallest != index) {
        swap(&heap[index], &heap[smallest]);
        heapifyDown(smallest);
    }
}

// Extract the minimum element from the heap
int extractMin() {
    if (size <= 0) {
        printf("Heap is empty\n");
        return -1;
    }
    int root = heap[0];
    heap[0] = heap[--size];  // Move the last element to the root and decrease the size
    heapifyDown(0);          // Heapify down to maintain the Min-Heap property
    return root;
}

// Print the elements of the Min-Heap
void printHeap() {
    for (int i = 0; i < size; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

int main() {
    // Insert elements into the Min-Heap
    insert(10);
    insert(20);
    insert(5);
    insert(30);
    insert(25);

    printf("Heap elements: ");
    printHeap();

    printf("Extracted min: %d\n", extractMin());

    printf("Heap after extraction: ");
    printHeap();

    return 0;
}

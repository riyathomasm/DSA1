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

// Heapify up - Used after insertion
void heapifyUp(int index) {
    if (index && heap[(index - 1) / 2] < heap[index]) {
        // Swap if the parent is smaller than the current node
        swap(&heap[(index - 1) / 2], &heap[index]);
        // Recursively heapify up the parent node
        heapifyUp((index - 1) / 2);
    }
}

// Insert a new element in the heap
void insert(int value) {
    if (size >= MAX_SIZE) {
        printf("Heap is full\n");
        return;
    }
    heap[size] = value;  // Insert the new value at the end of the heap
    heapifyUp(size);     // Heapify up to maintain heap property
    size++;              // Increase the size of the heap
}

// Heapify down - Used after deletion
void heapifyDown(int index) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int largest = index;

    // Find the largest among root, left child, and right child
    if (left < size && heap[left] > heap[largest]) {
        largest = left;
    }
    if (right < size && heap[right] > heap[largest]) {
        largest = right;
    }

    // Swap and continue heapifying if root is not the largest
    if (largest != index) {
        swap(&heap[index], &heap[largest]);
        heapifyDown(largest);
    }
}

// Extract the maximum element from the heap
int extractMax() {
    if (size <= 0) {
        printf("Heap is empty\n");
        return -1;
    }
    int root = heap[0];
    heap[0] = heap[--size];  // Move the last element to the root and decrease the size
    heapifyDown(0);          // Heapify down to maintain heap property
    return root;
}

// Print the elements of the heap
void printHeap() {
    for (int i = 0; i < size; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

int main() {
    // Insert elements into the heap
    insert(10);
    insert(20);
    insert(5);
    insert(30);
    insert(25);

    printf("Heap elements: ");
    printHeap();

    printf("Extracted max: %d\n", extractMax());

    printf("Heap after extraction: ");
    printHeap();

    return 0;
}


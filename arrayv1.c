#include <stdio.h>

#define MAX_SIZE 100

// Function to insert an element at the beginning
void insertAtBeginning(int arr[], int* size, int data) {
    for (int i = *size; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = data;
    (*size)++;
}

// Function to insert an element at the end
void insertAtEnd(int arr[], int* size, int data) {
    arr[(*size)++] = data;
}

// Function to insert an element at a specific position
void insertAtPosition(int arr[], int* size, int data, int position) {
    if (position < 0 || position > *size) {
        printf("Invalid position\n");
        return;
    }
    for (int i = *size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = data;
    (*size)++;
}

// Function to delete an element from the beginning
void deleteAtBeginning(int arr[], int* size) {
    if (*size == 0) {
        printf("Array is empty\n");
        return;
    }
    for (int i = 0; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}
 
// Function to delete an element from the end
void deleteAtEnd(int arr[], int* size) {
    if (*size == 0) {
        printf("Array is empty\n");
        return;
    }
    (*size)--;
}

// Function to delete an element from a specific position
void deleteAtPosition(int arr[], int* size, int position) {
    if (position < 0 || position >= *size) {
        printf("Invalid position\n");
        return;
    }
    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}

// Function to search for an element
int search(int arr[], int size, int data) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == data) {
            return i;
        }
    }
    return -1;
}

// Function to sort the array using bubble sort
void sort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to merge two sorted arrays into a single sorted array
void merge(int arr1[], int size1, int arr2[], int size2, int arr3[]) {
    int i = 0, j = 0, k = 0;
    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            arr3[k++] = arr1[i++];
        } else {
            arr3[k++] = arr2[j++];
        }
    }
    while (i < size1) {
        arr3[k++] = arr1[i++];
    }
    while (j < size2) {
        arr3[k++] = arr2[j++];
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[MAX_SIZE];
    int size = 0;

    int choice;
    int data, position;
    int arr1[MAX_SIZE], arr2[MAX_SIZE], arr3[MAX_SIZE];
    int size1, size2;

    while (1) {
        printf("\n1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete at beginning\n");
        printf("5. Delete at end\n");
        printf("6. Delete at position\n");
        printf("7. Search\n");
        printf("8. Sort\n");
        printf("9. Merge\n");
        printf("10. Exit\n");
        printf("11. print\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                insertAtBeginning(arr, &size, data);
                printArray(arr, size);
                break;
            case 2:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                insertAtEnd(arr, &size, data);
                printArray(arr, size);
                break;
            case 3:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                printf("Enter the position: ");
                scanf("%d", &position);
                insertAtPosition(arr, &size, data, position);
                printArray(arr, size);
                break;
            case 4:
                deleteAtBeginning(arr, &size);
                printArray(arr, size);
                break;
            case 5:
                deleteAtEnd(arr, &size);
                printArray(arr, size);
                break;
            case 6:
                printf("Enter the position: ");
                scanf("%d", &position);
                deleteAtPosition(arr, &size, position);
                printArray(arr, size);
                break;
            case 7:
                printf("Enter the element to search: ");
                scanf("%d", &data);
                position = search(arr, size, data);
                if (position != -1) {
                    printf("Element found at position %d\n", position);
                } else {
                    printf("Element not found\n");
                }
                break;
            case 8:
                sort(arr, size);
                printArray(arr, size);
                break;
            case 9:
                printf("Enter the size of the first array: ");
                scanf("%d", &size1);
                printf("Enter the elements of the first array: ");
                for (int i = 0; i < size1; i++) {
                    scanf("%d", &arr1[i]);
                }
                printf("Enter the size of the second array: ");
                scanf("%d", &size2);
                printf("Enter the elements of the second array: ");
                for (int i = 0; i < size2; i++) {
                    scanf("%d", &arr2[i]);
                }
                merge(arr1, size1, arr2, size2, arr3);
                printf("Merged array: ");
                printArray(arr3, size1 + size2);
                break;
            case 10:
                return 0;
            case 11:
            printArray(arr, size);break;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

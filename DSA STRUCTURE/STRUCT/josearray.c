#include <stdio.h>
#include <stdlib.h>

void Josephus(int n, int k) {
    int *person = (int *)malloc(n * sizeof(int));

    // Initialize the array of people
    for (int i = 0; i < n; i++) {
        person[i] = i + 1;
    }

    int index = 0;
    while (n > 1) {
        // Calculate the index of the person to be eliminated
        index = (index + k - 1) % n;
        printf("Person %d is eliminated.\n", person[index]);

        // Shift elements left to remove the person
        for (int i = index; i < n - 1; i++) {
            person[i] = person[i + 1];
        }

        // Reduce the count of people
        n--;

    }

    // Print the last remaining person
    printf("The survivor is person %d\n", person[0]);

    // Free the allocated memory
    free(person);
}

int main() {
    int n, k;

    // Input number of people and the step count
    printf("Enter the total number of people: ");
    scanf("%d", &n);

    printf("Enter the elimination step (k): ");
    scanf("%d", &k);

    // Call the Josephus function
    Josephus(n, k);

    return 0;
}

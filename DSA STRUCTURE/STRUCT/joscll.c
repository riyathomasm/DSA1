#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the circular linked list
struct node {
    int player_id;
    struct node* next;
};

int main() {
    int n, k, i, count;
    struct node *start, *ptr, *new_node;

    // Input the number of players and the value of k
    printf("\nEnter the number of players: ");
    scanf("%d", &n);
    printf("\nEnter the value of k (every k-th player gets eliminated): ");
    scanf("%d", &k);

    // Create the circular linked list
    start = (struct node*)malloc(sizeof(struct node));
    start->player_id = 1;
    ptr = start;

    for (i = 2; i <= n; i++) {
        new_node = (struct node*)malloc(sizeof(struct node));
        ptr->next = new_node;
        new_node->player_id = i;
        ptr = new_node;
    }
    ptr->next = start; // Complete the circular linkage

    // Process the elimination of players
    while (count > 1) {
        for (i = 0; i < k - 1; ++i) {
            ptr = ptr->next;
        }
        // Eliminate the k-th player
        struct node* temp = ptr->next;
        ptr->next = temp->next;
        free(temp);
        count--;
    }

    // Print the winner
    printf("\nThe Winner is Player %d\n", ptr->player_id);

    // Clean up the remaining node
    free(ptr);

    return 0;
}

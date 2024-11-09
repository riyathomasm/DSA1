#include <stdio.h>

int main() {
    // Input
    int a[4][5], i, j, z = 0, nz = 0;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 5; j++) {
            printf("Enter number: ");
            scanf("%d", &a[i][j]);
        }
    }

    // Output
    printf("\n2D Matrix is:\n");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 5; j++) {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }

    // Count factor
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 5; j++) {
            if (a[i][j] == 0) {
                z++;
            } else {
                nz++;
            }
        }
    }

    if (nz > z) {
        printf("\nDense Matrix\n");
    } else {
        int s[nz][3], k = 0; // Changed 5 to 3
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 5; j++) {
                if (a[i][j] != 0) {
                    s[k][0] = i;
                    s[k][1] = j;
                    s[k][2] = a[i][j];
                    k++;
                }
            }
        }
        printf("Sparse Matrix:\n");
        for (i = 0; i < nz; i++) {
            for (j = 0; j < 3; j++) { // Changed 5 to 3
                printf("%d\t", s[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
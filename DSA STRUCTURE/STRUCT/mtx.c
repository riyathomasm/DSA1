#include<stdio.h>
#include<stdlib.h>

void multiply(int **m1, int **m2, int **result, int R1, int C1, int R2, int C2){
    printf("resultant matrix is: \n");

    //now we begin our row fo loop
    for(int i = 0; i < R1; i++){
        for(int j = 0; j<C2; j++){
            result[i][j] = 0;

            for(int k = 0; k < R2; k++){
                result[i][j] += m1[i][k] * m2[k][j];
            }

            printf("%d\t", result[i][j]);
        }
        printf("\n");
    }
}

int main(){

    int R1, C1, R2, C2;

    printf("Enter number of rows for matrix 1: ");
    scanf("%d", &R1);

    printf("Enter number of columns for matrix 1: ");
    scanf("%d", &C1);

    printf("Enter number of rows for matrix 2: ");
    scanf("%d", &R2);

    printf("Enter number of columns for matrix 2: ");
    scanf("%d", &C2);

    if(C1 != R2){
        printf("Matrix multiplication is not possible.\n");
        return 0;
    }

    int **m1 = (int **)malloc(R1 * sizeof(int *));
    for(int i = 0; i < R1; i++){
        m1[i] = (int *)malloc(C1 * sizeof(int));
    }

    int **m2 = (int **)malloc(R2 * sizeof(int *));
    for(int i = 0; i < R2; i++){
        m2[i] = (int *)malloc(C2 * sizeof(int));
    }

    int **result = (int **)malloc(R1 * sizeof(int *));
    for(int i = 0; i < R1; i++){
        result[i] = (int *)malloc(C2 * sizeof(int));
    }

    // Input m1 and m2
    printf("Enter elements of matrix 1:\n");
    for(int i = 0; i < R1; i++){
        for(int j = 0; j < C1; j++){
            scanf("%d", &m1[i][j]);
        }
    }

    printf("Enter elements of matrix 2:\n");
    for(int i = 0; i < R2; i++){
        for(int j = 0; j < C2; j++){
            scanf("%d", &m2[i][j]);
        }
    }

    multiply(m1, m2, result, R1, C1, R2, C2);

    // Don't forget to free the memory when you're done
    for(int i = 0; i < R1; i++){
        free(m1[i]);
    }
    free(m1);

    for(int i = 0; i < R2; i++){
        free(m2[i]);
    }
    free(m2);

    for(int i = 0; i < R1; i++){
        free(result[i]);
    }
    free(result);

    return 0;
}

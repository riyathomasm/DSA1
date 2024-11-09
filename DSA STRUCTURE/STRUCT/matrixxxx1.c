#include<stdio.h>
#include<stdlib.h>

#define R1 3
#define C1 3
#define R2 3
#define C2 3

void multiply(int m1[][C1], int m2[][C2]){
    int result [R1][C2];
    
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

    int m1[R1][C1] = { { 1,1,1}, {1,0,1},{0,0,1}};
    int m2[R2][C2] = { { 2,2,2},{2,0,2},{2,2,1}};

    multiply(m1, m2);

    return 0;
}
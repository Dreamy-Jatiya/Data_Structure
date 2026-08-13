//31. Read two 2x2 matrices and perform addition of matrices into third matrix and print it 

#include<stdio.h>
void main(){
    int matrix1[2][2], matrix2[2][2], sum[2][2];

    printf("Enter the elements of first 2x2 matrix:\n");
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("Enter the elements of second 2x2 matrix:\n");
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            scanf("%d", &matrix2[i][j]);
        }
    }

    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            sum[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    printf("Sum of the two matrices:\n");
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }
}

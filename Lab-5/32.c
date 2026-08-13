//32. Read two matrices, first 3x2 and second 2x3, perform multiplication operation 
//    and store result in third matrix and print it.

#include<stdio.h>
void main(){

    int matrix1[3][2], matrix2[2][3], product[3][3];
    
    printf("Enter the elements of first 3x2 matrix:\n");
    for(int i=0; i<3; i++){
        for(int j=0; j<2; j++){
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("Enter the elements of second 2x3 matrix:\n");
    for(int i=0; i<2; i++){
        for(int j=0; j<3; j++){
            scanf("%d", &matrix2[i][j]);
        }
    }

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            product[i][j] = 0;
            for(int k=0; k<2; k++){
                product[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    printf("Product of the two matrices:\n");
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("%d ", product[i][j]);
        }
        printf("\n");
    }
}
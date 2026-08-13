//22. WAP to print Pascal triangle. 

#include <stdio.h>
int main() 
{
    int row;
    printf("Enter number of rows you want: ");
    scanf("%d", &row);

    for (int i = 0; i < row; i++) 
    {
        // 1. Print leading spaces to make it look like a triangle
        for (int j = 0; j < row - i - 1; j++) 
        {
            printf(" ");
        }

        int val = 1; // The first element of every row is always 1
        
        // 2. Calculate and print the elements of the row
        for (int k = 0; k<= i; k++) 
        {
            printf("%d ", val);
            
            // Binomial coefficient formula to get the next element in the row
            val = val * (i - k) / (k+ 1);
        }
        
        printf("\n"); 
    }

    return 0;
}

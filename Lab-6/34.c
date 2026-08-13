//34. WAP to allocate and de-allocate memory for int, char and float variable at runtime. 

#include <stdio.h>
#include <stdlib.h>

void main()
{
    int *p1;
    char *p2;
    float *p3;

    // // Allocating memory for int, char and float variable
    p1 = (int *)malloc(sizeof(int));
    p2 = (char *)malloc(sizeof(char));
    p3 = (float *)malloc(sizeof(float));

     // Check if memory allocation was successful
    if (ptr_int == NULL || ptr_char == NULL || ptr_float == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    // Assigning values to the allocated memory
    printf("Enter integer : ");
    scanf("%d", p1);
    printf("Enter character : ");
    scanf(" %c", p2);
    printf("Enter float : ");
    scanf("%f", p3);


    // Printing the values
    printf("\nInteger : value = %d & address = %d\n", *p1, p1);
    printf("Character : value = %c & address = %d\n", *p2, p2);
    printf("Float : value = %.2f & address = %d", *p3, p3);

    // De-allocating the memory
    free(p1);
    free(p2);
    free(p3);
}
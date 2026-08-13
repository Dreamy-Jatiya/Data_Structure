//24. Write a program to insert a number at a given location in an array. 

#include <stdio.h>

void main(){
    int total_elements, location, number;

    printf("Enter the total number of elements in the array: ");
    scanf("%d", &total_elements);

    int arr[total_elements];

    for (int i = 0; i < total_elements; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Enter the location where you want to insert the number (1 to %d): ", total_elements + 1);
    scanf("%d", &location);

    printf("Enter the number you want to insert: ");
    scanf("%d", &number);

    arr[location - 1] = number;

    for (int i = 0; i < total_elements + 1; i++) {
        printf("element %d: %d\n", i + 1, arr[i]);
    }

}
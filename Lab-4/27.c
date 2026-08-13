//27. Write a program to delete a number from an array that is already sorted in an 
//    ascending order. 
// Delete a number from a sorted array by shifting the remaining elements left.

#include<stdio.h>
void main(){
    int total_elements , number;

    // Read the current size of the array.
    printf("Enter the total number of elements in the array: ");
    scanf("%d", &total_elements);

    // Store the input elements.
    int arr[total_elements];

    // Read each array element from the user.
    for (int i = 0; i < total_elements; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Sort the array in ascending order.
    for (int i = 0; i < total_elements - 1; i++) {
        for (int j = 0; j < total_elements - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Read the value to delete.
    printf("Enter the number you want to delete: ");
    scanf("%d", &number);

    // Find the matching value and shift later elements one position left.
    for (int i = 0; i < total_elements; i++) {
        if (arr[i] == number) {
            for (int j = i; j < total_elements - 1; j++) {
                arr[j] = arr[j + 1];
            }
            total_elements--;
            break;
        }
    }

    // Print the updated array.
    for (int i = 0; i < total_elements; i++) {
        printf("element %d: %d\n", i + 1, arr[i]);
    }
}
//28. Write a program to delete duplicate numbers from an array.
// Remove duplicate values from an array by shifting later elements left.

#include<stdio.h>
void main(){
    int total_elements;

    // Read the size of the array.
    printf("Enter the total number of elements in the array: ");
    scanf("%d", &total_elements);

    // Store the array elements entered by the user.
    int arr[total_elements];

    // Read each element into the array.
    for (int i = 0; i < total_elements; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Compare each element with the elements after it.
    for (int i = 0; i < total_elements; i++) {
        for (int j = i + 1; j < total_elements; j++) {
            if (arr[i] == arr[j]) {
                // Shift the remaining values left to remove the duplicate.
                for (int k = j; k < total_elements - 1; k++) {
                    arr[k] = arr[k + 1];
                }
                total_elements--;
                j--;
            }
        }
    }

    // Print the array after duplicates are removed.
    for (int i = 0; i < total_elements; i++) {
        printf("element %d: %d\n", i + 1, arr[i]);
    }
}
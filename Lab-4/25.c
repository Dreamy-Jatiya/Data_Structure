//25. Write a program to delete a number from a given location in an array. 
// Delete a number from a given location in an array by shifting later elements left.

#include<stdio.h>
void main(){
    int total_elements, location;

    // Read the current number of elements.
    printf("Enter the total number of elements in the array: ");
    scanf("%d", &total_elements);

    // Store the array elements entered by the user.
    int arr[total_elements];

    // Read each element of the array.
    for (int i = 0; i < total_elements; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Ask for the 1-based location of the element to delete.
    printf("Enter the location from where you want to delete the number (1 to %d): ", total_elements);
    scanf("%d", &location);

    // Shift all elements after the chosen location one step to the left.
    for (int i = location - 1; i < total_elements - 1; i++) {
        arr[i] = arr[i + 1];
    }

    // Print the updated array after deletion.
    for (int i = 0; i < total_elements - 1; i++) {
        printf("element %d: %d\n", i + 1, arr[i]);
    }

}
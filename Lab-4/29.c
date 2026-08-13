//29. Write a program to merge two unsorted arrays. 

// Merge two unsorted arrays into one combined array.
#include<stdio.h>
void main(){
    int total_elements1, total_elements2;

    // Read the size of the first array.
    printf("Enter the total number of elements in the first array: ");
    scanf("%d", &total_elements1);

    // Read the size of the second array.
    printf("Enter the total number of elements in the second array: ");
    scanf("%d", &total_elements2);

    // Create storage for both input arrays and the merged result.
    int arr1[total_elements1];
    int arr2[total_elements2];
    int merged_arr[total_elements1 + total_elements2];

    // Read the first array.
    printf("Enter elements of the first array:\n");
    for (int i = 0; i < total_elements1; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr1[i]);
    }

    // Read the second array.
    printf("Enter elements of the second array:\n");
    for (int i = 0; i < total_elements2; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr2[i]);
    }

    // Copy the first array into the merged array.
    for (int i = 0; i < total_elements1; i++) {
        merged_arr[i] = arr1[i];
    }

    // Append the second array after the first one.
    for (int i = 0; i < total_elements2; i++) {
        merged_arr[total_elements1 + i] = arr2[i];
    }

    // Print the combined result.
    printf("Merged array:\n");
    for (int i = 0; i < total_elements1 + total_elements2; i++) {
        printf("Element %d: %d\n", i + 1, merged_arr[i]);
    }
}
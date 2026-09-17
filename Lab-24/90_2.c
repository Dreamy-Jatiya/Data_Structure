//90. Write a program to implement a Binary Search using Array.
//    Using Recursive

#include <stdio.h>

int binarySearchRecursive(int arr[], int low, int high, int target) {
    if (low > high)
        return -1;

    int mid = (low + high) / 2;

    if (arr[mid] == target)
        return mid;
    else if (arr[mid] < target)
        return binarySearchRecursive(arr, mid + 1, high, target);
    else
        return binarySearchRecursive(arr, low, mid - 1, target);
}

void main() {
    int n, i, target;

    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\nBinary Search (Recursive)\n");
    int resultRec = binarySearchRecursive(arr, 0, n - 1, target);
    if (resultRec != -1)
        printf("Element found at index %d\n", resultRec);
    else
        printf("Element not found\n");
}
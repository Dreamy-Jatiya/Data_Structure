//93. Write a program to implement Insertion Sort using Array. 

#include <stdio.h>
void insertionSort(int arr[], int n)
{
    // First element already sorted consider kariye.
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];

        // Sorted portion no last element.
        int j = i - 1;

        // Key karta mota elements ne right shift karo.
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        // Key ne correct position par insert karo.
        arr[j + 1] = key;
    }
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6};
    int n = 5;

    insertionSort(arr, n);

    printf("Sorted array: ");

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
//94. Write a program to implement Merge Sort using Array.

#include <stdio.h>
void merge(int arr[], int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int k = 0;

    int temp[right - left + 1];

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    
    while (i <= mid)
        temp[k++] = arr[i++];
    
    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left, k = 0; i <= right; i++, k++)
        arr[i] = temp[k];
}


void mergeSort(int arr[], int left, int right)
{
    // Single element already sorted hoy che.
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    // Left half sort karo.
    mergeSort(arr, left, mid);

    // Right half sort karo.
    mergeSort(arr, mid + 1, right);

    // Banney sorted halves merge karo.
    merge(arr, left, mid, right);
}

int main()
{
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = 7;

    mergeSort(arr, 0, n - 1);

    printf("Sorted array: ");

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
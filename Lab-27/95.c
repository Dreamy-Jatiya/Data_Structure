//Write a program to implement Quick Sort using Array.

#include <stdio.h>

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int i = low;
        int j = high;
        int pivot = arr[low];

        while (i < j)
        {
            while (arr[i] <= pivot && i < high)
                i++;

            while (arr[j] > pivot)
                j--;

            if (i < j)
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        // Place pivot in correct position
        int temp = arr[low];
        arr[low] = arr[j];
        arr[j] = temp;

        quickSort(arr, low, j - 1);
        quickSort(arr, j + 1, high);
    }
}

int main()
{
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    quickSort(arr, 0, n - 1);

    printf("Sorted array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
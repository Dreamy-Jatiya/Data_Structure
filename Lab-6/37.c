//37. WAP to find the largest element in the array using Pointer.

#include<stdio.h>
void main(){
    int total_elements;
    printf("Enter the number of elements: ");
    scanf("%d", &total_elements);

    int arr[total_elements];
    int *ptr = arr;

    for (int i = 0; i < total_elements; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &ptr[i]);
    }

    int max = ptr[0];

    for (int i = 0; i < total_elements; i++)
    {
        if (ptr[i] > max)
        {
            max = ptr[i];
        }
    }
    printf("The largest element is: %d", max);
}
//38. WAP to sort the array elements using Pointer. 

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

    for (int i = 0; i < total_elements - 1; i++)
    {
        for (int j = 0; j < total_elements - i - 1; j++)
        {
            if (ptr[j] > ptr[j + 1])
            {
                int temp = ptr[j];
                ptr[j] = ptr[j + 1];
                ptr[j + 1] = temp;
            }
        }
    }

    printf("The sorted array is: ");
    for (int i = 0; i < total_elements; i++)
    {
        printf("%d ", ptr[i]);
    }
}
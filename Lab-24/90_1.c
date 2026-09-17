//90. Write a program to implement a Binary Search using Array. 
//    Using Iterative
#include <stdio.h>

void main()
{
    int n, i, target;

    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &target);

    int low = 0, high = n - 1 , mid;
    int flag = 0 ;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (arr[mid] == target)
            {printf("element found at index : %d " , mid);flag = 1 ;break;}
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    if (flag == 0)
    {
        printf("\nelement didn't found .");
    }
    
}
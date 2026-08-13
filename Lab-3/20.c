// 20. Write a program to find whether the array contains a duplicate number or not. 

#include<stdio.h>
void main()
{
    int size;
    int duplicate=0;
    printf("enter size of array:");
    scanf("%d",&size);
    int arr[size];
    for(int i=0;i<size;i++)
    {
        printf("enter element");
        scanf("%d",&arr[i]);
    }

    for(int i=0;i<size-1;i++)
    {
        for(int j=i+1;j<size;j++)
        {
        if(arr[i]==arr[j])
        {
        duplicate++;
        }
        }
    }

    if(duplicate==0)
    {
        printf("It does not contain duplicate element");
    }
    else
    {
        printf("It contain duplicate element");
    }
}
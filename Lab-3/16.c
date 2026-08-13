//16. Write a program to read and display n numbers using an array.

#include<stdio.h>
void main()
{
    int size;
    printf("enter size of array:");
    scanf("%d",&size);
    int arr[size];
    for(int i=0;i<size;i++)
    
    {
        printf("enter element");
        scanf("%d",arr[i]);
    }
    for(int i=0;i<size;i++)
    {
        printf("enter element %d",arr[i]);
    }
}
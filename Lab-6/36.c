//36. WAP to calculate the sum of n numbers using Pointer. 

#include<stdio.h>
void main(){
    int n, sum = 0;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    int *ptr = arr;

    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &ptr[i]);
        sum += ptr[i]; // Adding the save element to the sum
    }

    printf("The sum of the numbers is: %d\n", sum);
}
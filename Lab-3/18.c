//18. Write a program to calculate average of first n numbers. 

#include<stdio.h>
void main(){
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);

    int sum = 0;
    for (int i = 0; i < number; i++)
    {
        sum += i;
    }

    printf("Average of numbers from 0 to %d is: %.2f\n", number, (float)sum / number);
    
}

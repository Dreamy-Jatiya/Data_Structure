//21. Read n numbers in an array then read two different numbers, replace 1st 
//    number with 2nd number in an array and print its index and final array. 

#include<stdio.h>
void main(){
    int total_Numbers;

    printf("Enter the total numbers: ");
    scanf("%d", &total_Numbers);

    int numbers[total_Numbers];
    for (int i = 0; i < total_Numbers; i++)
    {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    for (int i = 0; i < total_Numbers; i++)
    {
        printf("Number %d: %d\n", i + 1, numbers[i]);
    }
    
    int number1, number2;
    printf("Enter the first number: ");
    scanf("%d", &number1);
    printf("Enter the second number: ");
    scanf("%d", &number2);

    //swap both numbers in the array
    for (int i = 0; i < total_Numbers; i++)
    {
        if (numbers[i] == number1)
        {
            numbers[i] = number2;
        }
        else if (numbers[i] == number2)
        {
            numbers[i] = number1;
        }
    }

    for (int i = 0; i < total_Numbers; i++)
    {
        printf("Number %d: %d\n", i + 1, numbers[i]);
    }
}
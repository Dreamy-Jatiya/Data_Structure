//19. Write a program to find position of the smallest number & the largest number 
//    from given n numbers. 

#include <stdio.h>
void main()
{
    int total_Numbers;

    printf("Enter the total numbers: ");
    scanf("%d", &total_Numbers);

    int numbers[total_Numbers];
    for (int i = 0; i < total_Numbers; i++)
    {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    int smallest_Number_index = 0;
    for (int i = 1; i < total_Numbers; i++)
    {
        if (numbers[i] < numbers[smallest_Number_index])
        {
            smallest_Number_index = i;
        }
    }

    int largest_Number_index = 0;
    for (int i = 1; i < total_Numbers; i++)
    {
        if (numbers[i] > numbers[largest_Number_index])
        {
            largest_Number_index = i;
        }
    }

    for (int i = 0; i < total_Numbers; i++)
    {
        printf("Number %d: %d\n", i , numbers[i]);
    }
    printf("Largest number index is: %d\n", largest_Number_index);
    printf("Smallest number index is: %d\n", smallest_Number_index);
}

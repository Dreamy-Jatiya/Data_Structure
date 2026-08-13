//13. WAP to print prime numbers between given interval. 

#include <stdio.h>
int main()
{
    int a, b, i, j, isPrime;
    printf("Enter starting point: ");
    scanf("%d", &a);
    printf("Enter ending point: ");
    scanf("%d", &b);

    for (i = a; i <= b; i++)
    {
        if (i < 2)
            continue;
        isPrime = 1;

        for (j = 2; j <= i / 2; j++)
        {
            if (i % j == 0)
            {
                isPrime = 0;
                break;
            }
        }

        if (isPrime)
        {
            printf("%d\n", i);
        }
    }

    return 0;
}
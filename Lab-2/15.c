//15. WAP to print Armstrong number from 1 to 1000. 

#include <stdio.h>
#include <math.h>
int main()
{
    int n, original, temp, digit = 0;
    int sum = 0;

    printf("Enter a number: ");
    scanf("%d", &n);

    original = n;
    temp = n;

    // Count digits
    while (temp != 0)
    {
        digit++;
        temp /= 10;
    }

    // Calculate Armstrong sum
    while (n != 0)
    {
        int rem = n % 10;
        sum += pow(rem, digit);
        n /= 10;
    }

    // Check Armstrong number
    if (sum == original)
    {
        printf("%d is an Armstrong number\n", original);
    }
    else
    {
        printf("%d is not an Armstrong number\n", original);
    }

    return 0;
}
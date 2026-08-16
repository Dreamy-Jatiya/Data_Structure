//59. How stack can be used to recognize strings aca, bcb, abcba, abbcbba? Write a 
//    program to solve the above problem. 

#include <stdio.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch)
{
    stack[++top] = ch;
}

char pop()
{
    return stack[top--];
}

int main()
{
    char str[MAX];
    int n, i;
    int flag = 1;

    printf("Enter a string: ");
    scanf("%s", str);

    n = strlen(str);

    // Push first half into stack
    for (i = 0; i < n / 2; i++)
    {
        push(str[i]);
    }

    // For odd length, skip the middle character
    if (n % 2 != 0)
    {
        i++;
    }

    // Compare second half with stack
    while (i < n)
    {
        if (str[i] != pop())
        {
            flag = 0;
            break;
        }
        i++;
    }

    if (flag == 1)
        printf("String is accepted (Palindrome)\n");
    else
        printf("String is rejected (Not a Palindrome)\n");

    return 0;
}

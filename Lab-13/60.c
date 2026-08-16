//60. Write a program to determine if an input character string is of the form aibi 
//    where i >= 1 i.e., Number of ‘a’ should be equal to number of ‘b’.

#include <stdio.h>
#include <string.h>

int main()
{
    char str[100], stack[100];
    int top = -1;
    int i, flag = 1;

    printf("Enter string: ");
    scanf("%s", str);

    // Push all 'a's
    for (i = 0; str[i] == 'a'; i++)
    {
        stack[++top] = 'a';
    }

    // There must be at least one 'a'
    if (i == 0)
        flag = 0;

    // Pop for every 'b'
    while (str[i] == 'b')
    {
        if (top == -1)
        {
            flag = 0;
            break;
        }

        top--;
        i++;
    }

    // Check whether all characters are processed
    if (str[i] != '\0')
        flag = 0;

    // Stack should be empty
    if (top != -1)
        flag = 0;

    if (flag == 1)
        printf("Accepted\n");
    else
        printf("Rejected\n");

    return 0;
}

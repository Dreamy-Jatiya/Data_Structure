//23. WAP to sort the N names in an alphabetical order. 

#include <stdio.h>
#include <string.h>
int main() 
{
    int size;
    printf("Enter number of names: ");
    scanf("%d", &size);

    char arr[size][50];
    char temp[50]; 
   
    for(int i = 0; i < size; i++)
    {
        printf("Enter name %d: ", i + 1);
        scanf("%s", arr[i]); 
    }

    for(int i = 0; i < size - 1; i++)
    {
        for(int j = i + 1; j < size; j++)
        {
            
            if(strcmp(arr[i], arr[j]) > 0)
            {
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);
            }
        }
    }
 
    printf("\nNames in alphabetical order:\n");
    for(int i = 0; i < size; i++)
    {
        printf("%s\n", arr[i]);
    }

    return 0;
}



/*--------------------------  OR  --------------------------------*/
/*
//WAP to sort the N names in an alphabetical order
#include <stdio.h>
#include <string.h>

void main()
{
    int total_Names;

    printf("Enter the total names: ");
    scanf("%d", &total_Names);

    char names[total_Names][100];
    for (int i = 0; i < total_Names; i++)
    {
        printf("Enter name %d: ", i + 1);
        scanf("%s", names[i]);
    }

    // Sort the names in alphabetical order
    for (int i = 0; i < total_Names - 1; i++)
    {
        for (int j = 0; j < total_Names - i - 1; j++)
        {
            if (strcmp(names[j], names[j + 1]) > 0)
            {
                char temp[100];
                strcpy(temp, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], temp);
            }
        }
    }

    printf("Names in alphabetical order:\n");
    for (int i = 0; i < total_Names; i++)
    {
        printf("%s\n", names[i]);
    }
}
*/


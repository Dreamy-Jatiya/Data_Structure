//39. WAP to check whether the string is Palindrome or not using Pointer. 

#include <stdio.h>
#include <stdlib.h>

struct Student
{
    int roll_no;
    char name[50];
    char branch[50];
    int batch_no;
};

void main()
{
    struct Student s;
    
    struct Student *s1 = (struct Student *)malloc(sizeof(struct Student));
    s1=&s;

    printf("Enter roll_no : ");
    scanf("%d", &s1->roll_no);
    printf("Enter name : ");
    scanf("%s", s1->name);
    printf("Enter branch : ");
    scanf("%s", s1->branch);
    printf("Enter batch_no : ");
    scanf("%d", &s1->batch_no);

    printf("\nDetails of student : \n");

    printf("Roll_no : %d\n", s1->roll_no);
    printf("Name : %s\n", s1->name);
    printf("Branch : %s\n", s1->branch);
    printf("Batch_no : %d\n", s1->batch_no);
}
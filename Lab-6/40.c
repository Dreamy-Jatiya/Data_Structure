//40. WAP to define a C structure named Student (roll_no, name, branch and 
//    batch_no) and also to access the structure members using Pointer.

#include<stdio.h>
struct Student
{
    int roll_no;
    char name[100];
    char branch[100];
    int branch_no;
};
void main(){
    int total_students;
    printf("Enter the total number of students: ");
    scanf("%d", &total_students);

    struct Student students[total_students];
    struct Student *ptr = students;

    for (int i = 0; i < total_students; i++)
    {
        printf("Enter details for student %d:\n", i + 1);
        printf("Roll No: ");
        scanf("%d", &ptr[i].roll_no);
        printf("Name: ");
        scanf("%s", ptr[i].name);
        printf("Branch: ");
        scanf("%s", ptr[i].branch);
        printf("Branch No: ");
        scanf("%d", &ptr[i].branch_no);
    }

    printf("\nStudent Details:\n");
    printf("Roll No\tName\tBranch\tBranch No\n");
    for (int i = 0; i < total_students; i++)
    {
        printf("%d\t%s\t%s\t%d\n", ptr[i].roll_no, ptr[i].name, ptr[i].branch, ptr[i].branch_no);
    }
}
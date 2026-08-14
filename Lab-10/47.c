//47. Write a program to sort elements of a linked list.

#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int info;
    struct Node *link;
};

void insert(struct Node **first , int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->info = data;
    newNode->link = NULL;
    if (*first == NULL)
    {
        *first = newNode;
    }
    else
    {
        struct Node *temp = *first;
        while (temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = newNode;
    }
}

void deleteNode(struct Node **first, int data)
{
    struct Node *temp = *first;
    struct Node *prev = NULL;

    while (temp != NULL)
    {
        if (temp->info == data)
        {
            if (prev == NULL)
            {
                *first = temp->link;
            }
            else
            {
                prev->link = temp->link;
            }

            free(temp);
            printf("Node deleted\n");
            return;
        }

        prev = temp;
        temp = temp->link;
    }

    printf("Data not found\n");
}

void display(struct Node *first)
{
    if (first == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = first;

    while (temp != NULL)
    {
        printf("%d -> ", temp->info);
        temp = temp->link;
    }

    printf("NULL\n");
}

void sort(struct Node **first)
{
    if (*first == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Node *temp1 = *first;
    struct Node *temp2 = NULL;
    int temp;

    while (temp1 != NULL)
    {
        temp2 = temp1->link;
        while (temp2 != NULL)
        {
            if (temp1->info > temp2->info)
            {
                temp = temp1->info;
                temp1->info = temp2->info;
                temp2->info = temp;
            }
            temp2 = temp2->link;
        }
        temp1 = temp1->link;
    }

    printf("List sorted successfully\n");
}
void main()
{
    int choice;
    struct Node *first = NULL;
    int data;

    while (1)
    {
        printf("1. Insert \n2.delete \n3.sort \n4.display \n5.exit \n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the data to be inserted : ");
            scanf("%d", &data);
            insert(&first, data);
            break;
        case 2:
            printf("Enter the data to be deleted : ");
            scanf("%d", &data);
            deleteNode(&first, data);
            break;
        case 3:
            sort(&first);
            break;
        case 4:
            display(first);
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice \n");
        }
    }
}

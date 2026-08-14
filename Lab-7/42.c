/*42. Write a menu driven program to implement following operations on the singly linked list.  
        --- Insert a node at the front of the linked list. 
        --- Display all nodes. 
        --- Delete a first node of the linked list. 
        --- Insert a node at the end of the linked list. 
        --- Delete a last node of the linked list. 
        --- Delete a node from specified position. 
        --- Count the no. of nodes in the linked list. 
*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node* link;
};

void insert_front(struct Node** first, int info)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->info = info;
    newNode->link = *first;

    *first = newNode;
}

void insert_end(struct Node** first , int info){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->info = info;
    newNode->link = NULL;

    if (*first == NULL)
    {
        *first = newNode;
    }
    else
    {
        struct Node* temp = *first;

        while (temp->link != NULL)
        {
            temp = temp->link;
        }

        temp->link = newNode;
    }
}

void delete_first(struct Node** first){
    if (*first == NULL)
    {
        printf("linked list is empty\n");
        return;
    }

    struct Node* temp = *first;
    *first = (*first)->link;
    free(temp);
}

void delete_last(struct Node** first){
    if (*first == NULL)
    {
        printf("linked list is empty\n");
        return;
    }

    if ((*first)->link == NULL)
    {
        free(*first);
        *first = NULL;
        return;
    }

    struct Node* temp = *first;

    while (temp->link->link != NULL)
    {
        temp = temp->link;
    }

    free(temp->link);
    temp->link = NULL;
}

void delete_from_position(struct Node** first, int position){
    if (*first == NULL)
    {
        printf("linked list is empty\n");
        return;
    }

    if (position == 1)
    {
        delete_first(first);
        return;
    }

    struct Node* temp = *first;

    for (int i = 1; temp != NULL && i < position - 1; i++)
    {
        temp = temp->link;
    }

    if (temp == NULL || temp->link == NULL)
    {
        printf("Position out of bounds\n");
        return;
    }

    struct Node* nodeToDelete = temp->link;
    temp->link = nodeToDelete->link;
    free(nodeToDelete);
}

void display_Nodes(struct Node** first){
    if (*first == NULL)
    {
        printf("linked list is empty\n");
        return;
    }

    struct Node* temp = *first;

    while (temp != NULL)
    {
        printf("%d ", temp->info);
        temp = temp->link;
    }
    printf("\n");
}

int count_nodes(struct Node** first){
    int count = 0;
    struct Node* temp = *first;

    while (temp != NULL)
    {
        count++;
        temp = temp->link;
    }

    return count;
}
void main(){
    struct Node* first = NULL;
    int choice ;

    while (1)
    {
        printf("1. Insert at front\n2. Insert at end\n3. Delete first\n4. Delete last\n5. Delete from position\n6. Count nodes\n7. Display\n8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            // Insert at front
            int info;
            printf("Enter info: ");
            scanf("%d", &info);
            insert_front(&first, info);
            break;
        case 2:
            // Insert at end
            int info;
            printf("Enter info: ");
            scanf("%d", &info);
            insert_end(&first, info);
            break;
        case 3:
            // Delete first
            delete_first(&first);
            break;
        case 4:
            // Delete last
            delete_last(&first);
            break;
        case 5:
            // Delete from position
            int position;
            printf("Enter position: ");
            scanf("%d", &position);
            delete_from_position(&first, position);
            break;

        case 6:
            // Count nodes
            int count = count_nodes(&first);
            printf("Number of nodes: %d\n", count);
            break;
        case 7:
            // Display
            display_Nodes(&first);
            break;
            break;
        case 8:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
}
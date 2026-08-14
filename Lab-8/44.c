//44. Write a program to remove the duplicates nodes from given sorted Linked List. 
//    Input: 1 → 1 → 6 → 13 → 13 → 13 → 27 → 27 
//    Output: 1 → 6 → 13 → 27 

#include<stdio.h>
#include<stdlib.h>
struct Node{
    int info;
    struct Node *link;
};


void insert_list(struct Node **first, int info){
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->info = info;
    new_node->link = NULL;

    if (*first == NULL || (*first)->info >= new_node->info) {
        new_node->link = *first;
        *first = new_node;
    } else {
        struct Node *save = *first;
        while (save->link != NULL && save->link->info < new_node->info) {
            save = save->link;
        }
        new_node->link = save->link;
        save->link = new_node;
    }
}

void display_list(struct Node **first){
    struct Node *current = *first;
    while (current != NULL) {
        printf("%d ", current->info);
        current = current->link;
    }
}

void sort_list(struct Node **first){
    if (*first == NULL) {
        return;
    }

    struct Node *current = *first;
    while (current != NULL) {
        struct Node *index = current->link;
        while (index != NULL) {
            if (current->info > index->info) {
                int temp = current->info;
                current->info = index->info;
                index->info = temp;
            }
            index = index->link;
        }
        current = current->link;
    }
}

void remove_duplicates(struct Node **first){
    struct Node *current = *first;
    while (current != NULL && current->link != NULL) {
        if (current->info == current->link->info) {
            struct Node *temp = current->link;
            current->link = temp->link;
            free(temp);
        } else {
            current = current->link;
        }
    }
}

void main(){
    int choice;
    struct Node *first= NULL;
    
    while (1)
    {
        printf(" 1. Insert in list\n 2. Display list\n 3. Remove duplicates\n 4. Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            /* code for inserting in list */
            int info;
            printf("Enter the data to be inserted in list: ");
            scanf("%d", &info);
            insert_list(&first , info);
            break;
        case 2:
            /* code for displaying list */
            display_list(&first);
            break;
        case 3:
            /* code for removing duplicates */
            remove_duplicates(&first);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
}
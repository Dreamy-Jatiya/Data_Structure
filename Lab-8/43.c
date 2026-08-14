//43. WAP to check whether 2 singly linked lists are same or not.

#include<stdio.h>
#include<stdlib.h>
struct Node{
    int info;
    struct Node *link;
};

void insert_list1(struct Node **first1, int info){
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->info = info;
    new_node->link = NULL;

    if (*first1 == NULL || (*first1)->info >= new_node->info) {
        new_node->link = *first1;
        *first1 = new_node;
    } else {
        struct Node *save = *first1;
        while (save->link != NULL && save->link->info < new_node->info) {
            save = save->link;
        }
        new_node->link = save->link;
        save->link = new_node;
    }
}

void insert_list2(struct Node **first2, int info){
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->info = info;
    new_node->link = NULL;

    if (*first2 == NULL || (*first2)->info >= new_node->info) {
        new_node->link = *first2;
        *first2 = new_node;
    } else {
        struct Node *save = *first2;
        while (save->link != NULL && save->link->info < new_node->info) {
            save = save->link;
        }
        new_node->link = save->link;
        save->link = new_node;
    }
}

void display_list1(struct Node **first1){
    struct Node *current = *first1;
    printf("List 1: ");
    while (current != NULL) {
        printf("%d ", current->info);
        current = current->link;
    }
    printf("\n");
}

void display_list2(struct Node **first2){
    struct Node *current = *first2;
    printf("List 2: ");
    while (current != NULL) {
        printf("%d ", current->info);
        current = current->link;
    }
    printf("\n");
}

void check_equal(struct Node **first1, struct Node **first2){
    struct Node *current1 = *first1;
    struct Node *current2 = *first2;

    while (current1 != NULL && current2 != NULL) {
        if (current1->info != current2->info) {
            printf("The lists are not equal.\n");
            return;
        }
        current1 = current1->link;
        current2 = current2->link;
    }

    if (current1 == NULL && current2 == NULL) {
        printf("The lists are equal.\n");
    } else {
        printf("The lists are not equal.\n");
    }
}

void main(){
    int choice;
    struct Node *first1= NULL, *first2= NULL;

    printf("Enter Data in Accending order\n");
    while (1)
    {
        printf(" 1. Insert in list 1\n 2. Insert in list 2\n 3. Display list 1\n 4. Display list 2\n 5. Check if lists are equal\n 6. Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            /* code for inserting in list 1 */
            int info;
            printf("Enter the data to be inserted in list 1: ");
            scanf("%d", &info);
            insert_list1(&first1 , info);
            break;
        case 2:
            /* code for inserting in list 2 */
            
            printf("Enter the data to be inserted in list 2: ");
            scanf("%d", &info);
            insert_list2(&first2, info);
            break;
        case 3:
            /* code for displaying list 1 */
            display_list1(&first1);
            break;
        case 4:
            /* code for displaying list 2 */
            display_list2(&first2);
            break;
        case 5:
            /* code for checking if lists are equal */
            check_equal(&first1, &first2);
            break;
        case 6:
            /* code for exiting */
            exit(0);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    }
}
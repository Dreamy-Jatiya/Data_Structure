//53. Write a program to perform addition of two polynomial equations using 
//    appropriate data structure.

#include <stdio.h>
#include <stdlib.h>
struct Node{
    int coeff;
    int exp;
    struct Node *link;
};

void insert(struct Node **first, int coeff, int exp)
{
    struct Node *temp = *first;

    // Check if exponent already exists
    while(temp != NULL)
    {
        if(temp->exp == exp)
        {
            temp->coeff += coeff;  // Add coefficients
            return;
        }
        temp = temp->link;
    }

    // Create new node if exponent not found
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->link = NULL;

    if(*first == NULL)
    {
        *first = newNode;
    }
    else
    {
        temp = *first;
        while(temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = newNode;
    }
}

void add_polynomials(struct Node *first1 , struct Node *first2 , struct Node **result){
    struct Node *temp1 = first1;
    struct Node *temp2 = first2;

    while(temp1 != NULL && temp2 != NULL){
        if(temp1->exp > temp2->exp){
            insert(result , temp1->coeff , temp1->exp);
            temp1 = temp1->link;
        }
        else if(temp1->exp < temp2->exp){
            insert(result , temp2->coeff , temp2->exp);
            temp2 = temp2->link;
        }
        else{
            insert(result , temp1->coeff + temp2->coeff , temp1->exp);
            temp1 = temp1->link;
            temp2 = temp2->link;
        }
    }

    while(temp1 != NULL){
        insert(result , temp1->coeff , temp1->exp);
        temp1 = temp1->link;
    }

    while(temp2 != NULL){
        insert(result , temp2->coeff , temp2->exp);
        temp2 = temp2->link;
    }

    printf("Polynomials added successfully\n");
}

void display(struct Node *first){
    struct Node *temp = first;
    while(temp != NULL){
        printf("%dx^%d ", temp->coeff , temp->exp);
        temp = temp->link;
        if(temp != NULL){
            printf("+ ");
        }
    }
    printf("\n");
}

void deleteNode(struct Node **first , int exp){
    if(*first == NULL){
        printf("List is empty\n");
        return;
    }

    struct Node *temp = *first;
    struct Node *prev = NULL;

    while(temp != NULL && temp->exp != exp){
        prev = temp;
        temp = temp->link;
    }

    if(temp == NULL){
        printf("Node not found\n");
        return;
    }

    if(prev == NULL){
        *first = temp->link;
    }
    else{
        prev->link = temp->link;
    }
    free(temp);
}

void main(){
    int choice ;
    struct Node *first1 = NULL;
    struct Node *first2 = NULL;
    struct Node *result = NULL;
    int coeff , exp;

    while(1){
        printf("1. Insert polynomial 1\n2. Insert polynomial 2\n3. Add polynomials\n4. Delete term from polynomial 1\n5. Delete term from polynomial 2\n6. Display polynomials\n7. Exit\n");
        printf("Enter choice: ");
        scanf("%d" , &choice);
        switch(choice){
            case 1:
                printf("Enter coefficient and exponent: ");
                scanf("%d %d" , &coeff , &exp);
                insert(&first1 , coeff , exp);
                break;
            case 2:
                printf("Enter coefficient and exponent: ");
                scanf("%d %d" , &coeff , &exp);
                insert(&first2 , coeff , exp);
                break;
            case 3:
                add_polynomials(first1 , first2 , &result);
                break;
            case 4:
                printf("Enter exponent of term to delete from polynomial 1: ");
                scanf("%d" , &exp);
                deleteNode(&first1 , exp);
                break;
            case 5:
                printf("Enter exponent of term to delete from polynomial 2: ");
                scanf("%d" , &exp);
                deleteNode(&first2 , exp);
                break;
            case 6:
                printf("Polynomial 1: ");
                display(first1);
                printf("Polynomial 2: ");
                display(first2);
                printf("Result: ");
                display(result);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}

//4. WAP to find the largest among the given three numbers by user. 

#include<stdio.h>
void main(){
    int num1, num2, num3;
    printf("Enter three numbers: ");
    scanf("%d %d %d", &num1, &num2, &num3);

    if(num1 >= num2 && num1 >= num3){
        printf("%d is the largest number.\n", num1);
    } else if(num2 >= num1 && num2 >= num3){
        printf("%d is the largest number.\n", num2);
    } else {
        printf("%d is the largest number.\n", num3);
    }
}
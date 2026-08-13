//8. WAP to find factorial of a number. (Using loop) 

#include<stdio.h>
void main(){
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);

    int factorial = 1 ;
    for(int i=1 ; i<=number ; i++){
        factorial *= i ;
    }
    printf("Factorial of %d is %d\n", number, factorial);
}
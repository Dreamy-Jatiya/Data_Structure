//10. WAP to reverse a number. 

#include<stdio.h>
void main(){
    int number ;

    printf("Enter A number to Reverse :");
    scanf("%d",&number);

    int reversed_Number ;
    
    while(number){
        int temp = number%10;
        reversed_Number = 10*reversed_Number + temp;
        number /= 10;
    }

    printf("Reversed Number : %d" , reversed_Number);
}
//9. WAP to find power of a number using loop. 

#include<stdio.h>
void main()
{
    int a,b,ans=1;
    printf("enter number a:");
    scanf("%d",&a);
     printf("enter power b:");
    scanf("%d",&b);

    for(int i=1;i<=b;i++)
    {
         ans= ans*a;
    }
    printf("power of given number is: %d",ans);
}
//17. Write a program to calculate sum of numbers from m to n. 

#include<stdio.h>
void main()
{
    int m,n,sum=0;
    printf("enter m starting:");
    scanf("%d",&m);
    printf("enter ending point n:");
    scanf("%d",&n);
    for(int i=m;i<=n;i++)
    {
        sum=sum+i;
    }
    printf("sum is:%d",sum);
}
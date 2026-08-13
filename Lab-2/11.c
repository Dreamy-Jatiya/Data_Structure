//11. WAP to find factors of a given number. 

#include<stdio.h>
void main()
{
    int n;
    printf("enter number :");
    scanf("%d",&n);
    
    for(int i=1;i<=n;i++)
    {
      if(n%i==0)
      {
        printf("%d\n",i);
      }
    }
}
#include<stdio.h>

int natural(int);

int main()
{
    int n,r;
    char c;
   a:
    printf("\n Enter the number of terms\n");
    scanf("%d",&n);
    r = natural(n);
    printf("The sum of natural numbers is %d\n",r);
    printf("\n Enter y to try again\n");
    scanf(" %c",&c);
    if(c=='y')
        goto a;
    return 0;
}

int natural(int n)
{
    if(n==0)
        return 0;
    else
        return n+natural(n-1);
    return 0;
}


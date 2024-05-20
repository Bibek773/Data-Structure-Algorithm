#include<stdio.h>

int fibo(int);
int main()
{
    int i,n,r;
    char c;
    a:
    printf("Enter the no of terms\n\n");
    scanf("%d",&n);
    for(i=0; i<n; i++){
        r=fibo(i);
        printf("%d \t",r);
    }
    printf("\n enter 'y' to try again\n");
    scanf(" %c",&c);		//to skip the white space in buffer memory
    if(c=='y')
        goto a;
    return 0;
}
int fibo(int n)
{
    if(n<=1)
        return n;
    else
        return fibo(n-1)+fibo(n-2);
}

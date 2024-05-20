#include<stdio.h>

void TOH(int, char, char, char);

int main()
{
    int n;
    printf("Enter number of disks\n");
    scanf("%d",&n);
    TOH(n, '0', 'D', 'T');
    return 0;


}
void TOH(int n, char A, char B, char C)
{

    if(n>0)
    {
        TOH(n-1, A, C, B);
        printf("Move disk %d from %c to %c \n",n, A,B);
        TOH(n-1, C, B, A);

    }
}

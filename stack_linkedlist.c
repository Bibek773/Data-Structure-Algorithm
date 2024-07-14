#include<stdio.h>
#include<stdlib.h>



void push(int);
void pop();
void display();
void peek();


struct node {
    int info;
    struct node* next;
};

struct node* head = NULL;

int main()
{
    int choice, data;
    while(1)
    {
        printf("Enter : \n1 for Push \n2 for Pop \n3 for Peek \n4 for Display \n5 for exit");
        scanf("%d",&data);
    }
    return 0;
}


#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int stack[MAX];
int top=-1;

void push(int);
int  pop();
void peek();
void display();
void exit();

int is_empty();
int is_full();

int main(){
    int choice, data;

        while(1){
    printf("Enter:");
    printf("\n1 for push \n2 for pop \n3 for peek \n4 for display \n5 for exit\n ");
    scanf("%d",&choice);
    switch(choice){
        case 1:
                printf("\nEnter data\n");
                scanf("%d",&data);
                push(data);
                printf("\n %d is Pushed successfully\n ", data);
                break;
        case 2:
                int  popped_data=pop();
                printf("\n %d is Pop successfully\n ", popped_data);
                break;
        case 3:

                peek();

                break;

        case 4:
                display();
            break;
        case 5:
                exit(0);
            break;
        default:
            printf("Enter the valid number");
    }
    }
    return 0;
}
int is_full(){
    if (top== MAX-1){
        return 1;
    }
    else{
        return 0;
    }
}
int is_empty(){
    if (top==-1){
        return 1;
    }
    else{
         return 0;
    }
}
void push( int data){
    if(is_full()){
        printf("\n Stack Overflow");
        exit(0);
    }
    else{
        top ++;
         stack[top] = data;
    }
}
int pop(){
    if(is_empty()){
        printf("Stack is empty");
        exit(0);
    }
    else{
        return stack[top--];
    }
}
void peek(){
    if(is_empty()){
        printf("Stack is empty");

    }
    else{
        printf("%d is in the top\n",stack[top]);

    }
}
void display(){
    if(is_empty()){
        printf(" \n stack is empty\n");
    }
    else{
        for(int i=0; i<=top; i++){
            printf("%d ",stack[i]);
        }
    }
}

#include <stdio.h>
#include<stdlib.h>
int ptr, head;

void enqueue(int);
void dequeue();
void display();
int is_full();
void first();
int is_empty();
void empty();

struct node{
    int info;
    int next;

};
int main()
{
    struct node* newnode;

    int choice, data;
    while(1){
    printf("\nEnter \n1 for Enqueue \n2 for Dequeue \n3 for Display \n4 for Front \n5 for Empty the QUEUE  \n6 for Exit: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            if(!is_full())
            {
                printf("\nEnter data: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            }
            else
            {
                printf("\nQueue overflow...");
                break;
            }
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            first();
            break;
        case 5:
            empty();
            break;
        case 6:
            exit(0);
        default:
            printf("\nInvalid Choice...");
    }
    }
    return 0;
}

void enqueue(int value)
{
    if(is_full())
    {
        printf("\nQueue overflow...");
        return;
    }

    else
    {
struct node* newnode = (struct node*)malloc(sizeof(struct node));

        newnode->next=NULL;
        newnode->info=value;
        if(head==NULL)
            head=newnode;
        printf("\n%d is enqueued successfully.", newnode->info);
    }
}

int is_empty()
{
    if(head==NULL)
        return 1;
    else
        return 0;
}


int is_full() {
    return (head == NULL) ? 1 : 0;
}



void dequeue() {
    if (is_empty()) {
        printf("\nQueue Underflow...");
        return;
    }
    printf("\n%d is dequeued successfully.", head->info);
    ptr = head;
    head = head->next;
    free(ptr);
    if (head == NULL) {
        printf("\nQueue is Empty now!!");
    }
}


void empty() {
    if (is_empty()) {
        printf("\nQueue Underflow...");
        return;
    }
    while (head != NULL) {
        ptr = head;
        head = head->next;
        free(ptr);
    }
    printf("\nQueue is Empty now!!");
}

void display() {
    if (is_empty()) {
        printf("\nQueue is empty.");
    } else {
        printf("\nThe elements in the queue are: ");
        ptr = head;
        while (ptr != NULL) {
            printf("\t%d", ptr->info);
            ptr = ptr->next;
        }
    }
}

void first()
{

    if(is_empty())
    {
        printf("\nQueue is empty.");
    }
    else
    {
        printf("\nThe first elements in the queue is: ");

            printf("%d\t", head->info);

    }
}



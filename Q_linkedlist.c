#include <stdio.h>
#include<stdlib.h>
int ptr, head;
#include <stdlib.h>


struct node {
    int info;
    struct node* next;
};


struct node* head = NULL;

void enqueue(int);
void dequeue();
@@ -10,115 +18,97 @@ void first();
int is_empty();
void empty();

struct node{
    int info;
    int next;

};
int main()
{
    struct node* newnode;

int main() {
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
    while (1) {
        printf("\nEnter \n1 for Enqueue \n2 for Dequeue \n3 for Display \n4 for Front \n5 for Empty the QUEUE  \n6 for Exit: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (!is_full()) {
                    printf("\nEnter data: ");
                    scanf("%d", &data);
                    enqueue(data);
                } else {
                    printf("\nQueue overflow...");
                }
                break;
            }
            else
            {
                printf("\nQueue overflow...");
            case 2:
                dequeue();
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
void enqueue(int value) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("\nMemory allocation failed...");
        return;
    }
    newnode->info = value;
    newnode->next = NULL;

    else
    {
struct node* newnode = (struct node*)malloc(sizeof(struct node));

        newnode->next=NULL;
        newnode->info=value;
        if(head==NULL)
            head=newnode;
        printf("\n%d is enqueued successfully.", newnode->info);
    if (head == NULL) {
        head = newnode;
    } else {
        struct node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    printf("\n%d is enqueued successfully.", value);
}

int is_empty()
{
    if(head==NULL)
        return 1;
    else
        return 0;
int is_empty() {
    return head == NULL;
}


int is_full() {
    return (head == NULL) ? 1 : 0;
}


    return 0;
}

void dequeue() {
    if (is_empty()) {
        printf("\nQueue Underflow...");
        return;
    }
    struct node* temp = head;
    printf("\n%d is dequeued successfully.", head->info);
    ptr = head;
    head = head->next;
    free(ptr);
    free(temp);

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
        struct node* temp = head;
        head = head->next;
        free(ptr);
        free(temp);
    }
    printf("\nQueue is Empty now!!");
}
@@ -128,28 +118,18 @@ void display() {
        printf("\nQueue is empty.");
    } else {
        printf("\nThe elements in the queue are: ");
        ptr = head;
        while (ptr != NULL) {
            printf("\t%d", ptr->info);
            ptr = ptr->next;
        struct node* temp = head;
        while (temp != NULL) {
            printf("\t%d", temp->info);
            temp = temp->next;
        }
    }
}

void first()
{

    if(is_empty())
    {
void first() {
    if (is_empty()) {
        printf("\nQueue is empty.");
    }
    else
    {
        printf("\nThe first elements in the queue is: ");

            printf("%d\t", head->info);

    } else {
        printf("\nThe first element in the queue is: %d", head->info);
    }
}

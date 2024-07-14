#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node* next;
};

struct node* head = NULL;

void enqueue(int value) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->info = value;
    newnode->next = NULL;

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

int is_empty() {
    return head == NULL;
}

void dequeue() {
    if (is_empty()) {
        printf("\nQueue Underflow...");
        return;
    }
    struct node* temp = head;
    printf("\n%d is dequeued successfully.", head->info);
    head = head->next;
    free(temp);
}

void empty() {
    while (!is_empty()) {
        dequeue();
    }
    printf("\nQueue is Empty now!!");
}

void display() {
    if (is_empty()) {
        printf("\nQueue is empty.");
    } else {
        printf("\nThe elements in the queue are: ");
        struct node* temp = head;
        while (temp != NULL) {
            printf("\t%d", temp->info);
            temp = temp->next;
        }
    }
}

void first() {
    if (is_empty()) {
        printf("\nQueue is empty.");
    } else {
        printf("\nThe first element in the queue is: %d", head->info);
    }
}

int main() {
    int choice, data;

    while (1) {
        printf("\nEnter \n1 for Enqueue \n2 for Dequeue \n3 for Display \n4 for Front \n5 for Empty the QUEUE  \n6 for Exit: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter data: ");
                scanf("%d", &data);
                enqueue(data);
                break;
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

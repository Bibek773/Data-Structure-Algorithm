#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next;
};

struct node *head = NULL;

// Function declarations
void insert_begin(int data);
void insert_end(int data);
void deletion_begin();
void deletion_end();
void display();
void sp(int data);
void dsp();

int main() {
    int choice, data;

    while (1) {
        system("clear"); // Use "cls" for Windows
        printf("\n Enter: \n1 for insertion in the beginning \n2 for insertion in the specified position \n3 for insertion in the end \n4 for deletion in the beginning \n5 for deletion in the end \n6 for deletion in the specified position \n7 for display \n8 for exit: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter data: ");
                scanf("%d", &data);
                insert_begin(data);
                break;
            case 2:
                printf("\nEnter data: ");
                scanf("%d", &data);
                sp(data);
                break;
            case 3:
                printf("\nEnter data: ");
                scanf("%d", &data);
                insert_end(data);
                break;
            case 4:
                deletion_begin();
                break;
            case 5:
                deletion_end();
                break;
            case 6:
                dsp();
                break;
            case 7:
                display();
                break;
            case 8:
                exit(0);
            default:
                printf("\n Enter a valid option..........");
                break;
        }
    }
    return 0;
}

void dsp() {
    struct node *ptr, *temp;
    int pos, i;
    if (head == NULL) {
        printf("\nThe list is empty");
        return;
    }

    printf("\nEnter the position to be deleted: ");
    scanf("%d", &pos);

    if (pos == 0) {
        ptr = head;
        head = head->next;
        printf("\nThe deleted element is %d\t", ptr->info);
        free(ptr);
    } else {
        ptr = head;
        for (i = 0; i < pos; i++) {
            temp = ptr;
            ptr = ptr->next;
            if (ptr == NULL) {
                printf("\nPosition not found:\n");
                return;
            }
        }
        temp->next = ptr->next;
        printf("\nThe deleted element is %d\t", ptr->info);
        free(ptr);
    }
}

void insert_begin(int data) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("\nNode creation failed");
        return;
    }

    newnode->info = data;
    newnode->next = head;
    head = newnode;
    printf("\n %d is inserted in the beginning ", newnode->info);
}

void sp(int data) {
    int i, pos;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("\nNode creation failed");
        return;
    }
    newnode->info = data;

    printf("\n Enter the position: ");
    scanf("%d", &pos);

    struct node *ptr = head;
    for (i = 0; i < pos - 1; i++) {
        ptr = ptr->next;
        if (ptr == NULL) {
            printf("\n Position not found:[handle with care]\n");
            free(newnode);
            return;
        }
    }
    newnode->next = ptr->next;
    ptr->next = newnode;
    printf("\n %d is inserted at position %d", newnode->info, pos);
}

void insert_end(int data) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("\nNode creation failed");
        return;
    }
    newnode->info = data;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
    } else {
        struct node *ptr = head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = newnode;
    }
    printf("\n %d is inserted in the end ", newnode->info);
}

void deletion_begin() {
    if (head == NULL) {
        printf("\n List is empty");
        return;
    } else {
        struct node *ptr = head;
        head = head->next;
        printf("\n %d is deleted from beginning", ptr->info);
        free(ptr);
    }
}

void deletion_end() {
    if (head == NULL) {
        printf("\n List is empty");
        return;
    } else if (head->next == NULL) {
        printf("\n %d is deleted from beginning", head->info);
        free(head);
        head = NULL;
    } else {
        struct node *ptr = head;
        struct node *temp;
        while (ptr->next != NULL) {
            temp = ptr;
            ptr = ptr->next;
        }
        temp->next = NULL;
        printf("\n%d is deleted from the end", ptr->info);
        free(ptr);
    }
}

void display() {
    if (head == NULL) {
        printf("\n The list is empty.");
    } else {
        printf("\n The data are as follows:\n");
        struct node *ptr = head;
        while (ptr != NULL) {
            printf("\t%d", ptr->info);
            ptr = ptr->next;
        }
        printf("\n");
    }
    sleep(2);
}

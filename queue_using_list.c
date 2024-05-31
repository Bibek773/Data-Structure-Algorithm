#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define UP_ARROW 72
#define DOWN_ARROW 80
#define ENTER 13

struct node {
    int info;
    struct node* next;
};

struct node* head = NULL;

void enqueue(int value);
void dequeue();
void display();
int is_full();
void first();
int is_empty();
void empty();
void displayMenu(int highlight, const char* menu[], int size);

void displayMenu(int highlight, const char* menu[], int size) {
    system("cls");
    for (int i = 0; i < size; i++) {
        if (i == highlight) {
            printf("-> %s\n", menu[i]);
        } else {
            printf("   %s\n", menu[i]);
        }
    }
}

int main() {
    const char* menuItems[] = {
        "Enqueue",
        "Dequeue",
        "Display",
        "Front",
        "Empty the QUEUE",
        "Exit"
    };
    int menuSize = sizeof(menuItems) / sizeof(menuItems[0]);
    int highlight = 0;
    int choice = 0;
    int key;

    while (1) {
        displayMenu(highlight, menuItems, menuSize);
        key = getch(); // Get key input

        if (key == 0 || key == 224) {
            // Handle arrow keys
            key = getch(); // Get the actual key
            switch (key) {
                case UP_ARROW:
                    if (highlight > 0) {
                        highlight--;
                    }
                    break;
                case DOWN_ARROW:
                    if (highlight < menuSize - 1) {
                        highlight++;
                    }
                    break;
            }
        } else if (key == ENTER) {
            choice = highlight;
            switch (choice) {
                case 0:
                    if (!is_full()) {
                        int data;
                        printf("\nEnter data: ");
                        scanf("%d", &data);
                        enqueue(data);
                    } else {
                        printf("\nQueue overflow...");
                    }
                    break;
                case 1:
                    dequeue();
                    break;
                case 2:
                    display();
                    break;
                case 3:
                    first();
                    break;
                case 4:
                    empty();
                    break;
                case 5:
                    printf("Exiting...\n");
                    return 0;
                default:
                    printf("\nInvalid Choice...");
            }
            printf("\nPress any key to return to the menu...");
            getch(); // Wait for user to acknowledge
        }
    }
    return 0;
}

void enqueue(int value) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("\nMemory allocation failed...");
        return;
    }
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

int is_full() {
    return 0;
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
        struct node* temp = head;
        head = head->next;
        free(temp);
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

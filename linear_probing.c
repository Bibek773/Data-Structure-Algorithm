#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int hash(int key) {
    return key % SIZE;
}

void insert(int hashTable[], int key) {
    int index = hash(key);
    while (hashTable[index] != -1) {
        index = (index + 1) % SIZE;
    }
    hashTable[index] = key;
}

void display(int hashTable[]) {
    printf("Hash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] == -1) {
            printf("%d: Empty\n", i);
        } else {
            printf("%d: %d\n", i, hashTable[i]);
        }
    }
}

int main() {
    int hashTable[SIZE], i, key;
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = -1;
    }
    for (i = 0; i < SIZE; i++) {
        printf("\nEnter key: ");
        scanf("%d", &key);
        insert(hashTable, key);
    }
    display(hashTable);
    return 0;
}

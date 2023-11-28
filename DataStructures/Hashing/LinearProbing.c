#include <stdio.h>
#include <stdlib.h>
 
struct Node {
    int key;
    int value;
};
 
const int capacity = 20;
int size = 0;
struct Node* find(struct Node** arr, int key);

int HashCode(int key){
    return key % capacity;
}

void Insert(struct Node** arr, int key, int V) {

    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    temp->key = key;
    temp->value = V;

    int hashIndex = HashCode(key);

    while (arr[hashIndex] != NULL && arr[hashIndex]->key != key && arr[hashIndex]->key != -1) {
        hashIndex++;
        hashIndex %= capacity;
    }

    if (arr[hashIndex] == NULL || arr[hashIndex]->key == -1) {
        size++;
    }
 
    arr[hashIndex] = temp;
}

int Delete(struct Node** arr, int key) {
    struct Node* found = find(arr, key);
    int hashIndex = HashCode(key);
    if(found != NULL){
        while (arr[hashIndex] != NULL && arr[hashIndex]->key != key && arr[hashIndex]->key != -1) {
            hashIndex++;
            hashIndex %= capacity;
        }
        arr[hashIndex] = NULL;
        free(found);
        size--;
        return 1;
    } else {
        return 0;
    }
}

struct Node* find(struct Node** arr, int key) {
    int hashIndex = HashCode(key);
    int counter = 0;

    while (arr[hashIndex] != NULL) {
        counter = 0;
        if (counter++ > capacity)
            break;

        if (arr[hashIndex]->key == key){
            return arr[hashIndex];
        }
        hashIndex = HashCode(hashIndex + 1);
    }

    return NULL;
}

void PrintHashTable(struct Node** arr){
    int i;
    struct Node* curr = *arr;
    for (i = 0; i < capacity; i++) {
        curr = arr[i];
        if (curr != NULL) {
            printf("address: %p Key: %d Value: %d\n", (void *) curr, curr->key, curr->value);
        }
    }
    if (curr == NULL && i == 0) {
        printf("\n Array empty\n");
    }
}

int main() {
    struct Node** arr = (struct Node**) malloc(capacity * sizeof(struct Node*));
    for (int i = 0; i < capacity; i++) {
        arr[i] = NULL;
    }

    Insert(arr, 4, 7);
    Insert(arr, 0, 1);
    Insert(arr, 1, 5);
    Insert(arr, 2, 15);
    Insert(arr, 3, 20);
    Insert(arr, 40, 70);
    Insert(arr, 5, 0);

    PrintHashTable(arr);

    struct Node* temp = find(arr, 4);
    printf("\nKey %d: Value: %d, address: %p", 4, temp->value, (void *) temp);
    temp = find(arr, 0);
    printf("\nKey %d: Value: %d, address: %p", 0, temp->value, (void *) temp);
    temp = find(arr, 40);
    printf("\nKey %d: Value: %d, address: %p", 40, temp->value, (void *) temp);
    printf("\n\nDeleting key 40\n");
    Delete(arr, 40);
    printf("\n");

    PrintHashTable(arr);
}
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct node {
    int key;
    int value;
    bool used;
    struct node *next;
} Node;

typedef struct hashtable {
    int max;
    int length;
    Node* table;
} HashTable;

void initTable(HashTable *ht, int capacity){

    ht->max = capacity;
    ht->length = 0;
    ht->table = (Node*) calloc(ht->max, sizeof(Node));
}
 
int hashcode(int key, int max) {
    return (key % max);
}

void insert(HashTable *ht, Node** node) {

    int hash = hashcode((*node)->key, ht->max);
    Node* temp = &ht->table[hash];
    if(!temp->used){
        ht->table[hash].key = (*node)->key;
        ht->table[hash].value = (*node)->value;
        ht->table[hash].used = true;
        (*node) = &ht->table[hash];
        ht->length += 1;
    }else {
        while(temp->next != NULL){
            temp = temp->next;
        }
        (*node)->used = true;
        temp->next = (*node);
        ht->length += 1;
    }
}

Node* search(HashTable *ht, int key){
    int hash = hashcode(key, ht->max);

    Node* temp = &ht->table[hash];
    while(temp != NULL){
        if(temp->key == key){
            break;
        }
        temp = temp->next;
    }
    
    return temp;
}

bool delete(HashTable *ht, int key){
    int hash = hashcode(key, ht->max);

    Node* temp = &ht->table[hash];
    Node* prev = NULL;
    bool result = false;
    if(temp->used){
        while(temp != NULL){
            if(temp->key == key){
                if(prev == NULL){
                    ht->table[hash].key = temp->next->key;
                    ht->table[hash].value = temp->next->value;
                    ht->table[hash].next = temp->next->next;
                    free(temp->next);
                    result = true;
                    break;
                } else {
                    prev->next = temp->next;
                    free(temp);
                    result = true;
                    break;
                }
            }
            prev = temp;
            temp = temp->next;
        }
    }

    return result;
}

void printNode(HashTable *ht, int key){

    Node* node = search(ht, key);

    if(node != NULL){
        printf("key: %d val: %d\n", node->key, node->value);
    } else {
        printf("Not found\n");
    }

}

int main() {

    HashTable* ht = (HashTable *)malloc(sizeof(HashTable));
    initTable(ht, 10);
    Node* n = (Node *)malloc(sizeof(Node));
    n->key = 10;
    n->value = 69;
    insert(ht, &n);

    Node* n2 = (Node *)malloc(sizeof(Node));
    n2->key = 2;
    n2->value = 13;
    insert(ht, &n2);

    Node* n3 = (Node *)malloc(sizeof(Node));
    n3->key = 20;
    n3->value = 79;
    insert(ht, &n3);
    Node* n4 = (Node *)malloc(sizeof(Node));
    n4->key = 30;
    n4->value = 99;
    insert(ht, &n4);

    delete(ht, 20);

    printNode(ht, 20);
}
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct node {
    int key;
    int value;
    bool used;
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

int index_incr_wrap(int index, int table_size){
    index++;
    if (index >= table_size){
        index = 0;
    }
    return index;
}

bool insert(HashTable *ht, Node** node) {

    int index = hashcode((*node)->key, ht->max);
    int first_key = ht->table[index].key;
    while(ht->table[index].used){
        index = index_incr_wrap(index, ht->max);
        if(ht->table[index].key == first_key){
            printf("Full\n");
            return 0;
        }
    }
    ht->table[index].key = (*node)->key;
    ht->table[index].value = (*node)->value;
    ht->table[index].used = true;
    (*node) = &ht->table[index];
    ht->length += 1;
    return 1;
}

Node* search(HashTable *ht, int key){
    int index = hashcode(key, ht->max);
    int first_key = ht->table[index].key;
    while(ht->table[index].used){
        if(ht->table[index].key == key){
            ht->table[index].key = 0;
            ht->table[index].value = 0;
            ht->table[index].used = 0;
            return 1;
        } else if(ht->table[index].key == first_key){
            printf("Full\n");
            return 0;
        }
        index = index_incr_wrap(index, ht->max);
    }
}

bool delete(HashTable *ht, int key){
    int index = hashcode(key, ht->max);
    int first_key = ht->table[index].key;
    while(ht->table[index].used){
        if(ht->table[index].key == key){
            return &ht->table[index];
        } else if(ht->table[index].key == first_key){
            printf("Full\n");
            return NULL;
        }
        index = index_incr_wrap(index, ht->max);
    }
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
    initTable(ht, 3);
    Node* n = (Node *)malloc(sizeof(Node));
    n->key = 11;
    n->value = 69;
    insert(ht, &n);

    Node* n2 = (Node *)malloc(sizeof(Node));
    n2->key = 23;
    n2->value = 13;
    insert(ht, &n2);

    Node* n3 = (Node *)malloc(sizeof(Node));
    n3->key = 221;
    n3->value = 79;
    insert(ht, &n3);
    Node* n4 = (Node *)malloc(sizeof(Node));
    n4->key = 30;
    n4->value = 99;
    insert(ht, &n4);

    delete(ht, 11);

    printNode(ht, 11);
}
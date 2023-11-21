#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "basic-ops.c"

// TODO usar hashing

struct Node* findInterseccionTwoPointer(struct Node* head1, struct Node* head2){

    struct Node* ptr1 = head1;
    struct Node* ptr2 = head2;

    // los punteros se persiguen el uno al otro, cambiando de lista
    while (ptr1 != ptr2) {

        ptr1 = ptr1->next;
        ptr2 = ptr2->next;

        if (ptr1 == ptr2)
            return ptr1;

        // una vez ambos se hayan reasignado, estarán a la misma distancia del nodo común, por eso esta forma es más rápida
        if (ptr1 == NULL)
            ptr1 = head2;

        if (ptr2 == NULL)
            ptr2 = head1;
    }

    return ptr1;
}

struct Node* findInterseccionTwoPointer2(struct Node* head1, struct Node* head2){

    struct Node* ptr1 = head1;
    struct Node* ptr2 = head2;

    // los punteros se persiguen el uno al otro, cambiando de lista
    while (ptr1 != ptr2) {

        ptr1 = ptr1->next;
        ptr2 = ptr2->next;

        if (ptr1 == ptr2)
            return ptr1;

        if (ptr1 == NULL)
            ptr1 = head1;

        if (ptr2 == NULL)
            ptr2 = head2;
    }

    return ptr1;
}


int main(){
    struct Node *list1=NULL, *list2=NULL;
    int r, i;
    clock_t start, end;
    double cpu_time_used1, cpu_time_used2;
    struct Node* intersec;

    list1 = malloc(sizeof(struct Node));
    for(i = 1; i < 300; i++){
        r = rand() % 100;
        AppendNew(list1, r);
    }

    list2 = malloc(sizeof(struct Node));
    for(i = 1; i < 301; i++){
        r = rand() % 100;
        AppendNew(list2, r);
    }

    struct Node* newNode, *ptr1=list1, *ptr2=list2;

    while(ptr1->next != NULL){
        ptr1 = ptr1->next;
    }
    while(ptr2->next != NULL){
        ptr2 = ptr2->next;
    }

    newNode = malloc(sizeof(struct Node));
    newNode->data = 15;
    ptr1->next = newNode;
    ptr2->next = newNode;
    newNode = malloc(sizeof(struct Node));
    newNode->data = 30;
    ptr1->next->next = newNode;
    newNode = malloc(sizeof(struct Node));
    newNode->data = 45;
    ptr1->next->next->next = newNode;
/*
    PrintList(list1);
    PrintList(list2);
*/

    start = clock();
    intersec = findInterseccionTwoPointer(list1, list2);
    end = clock();
    cpu_time_used1 = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Node: %p data: %d\n", &intersec, intersec->data);

    start = clock();
    intersec = findInterseccionTwoPointer2(list1, list2);
    end = clock();
    cpu_time_used2 = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Node: %p data: %d\n", &intersec, intersec->data);
    printf("\nTime taken swap list: %f\nTime taken stick to same list: %f\n", cpu_time_used1, cpu_time_used2);

}
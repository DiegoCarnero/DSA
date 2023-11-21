#include<stdio.h>
#include<stdlib.h>
#include "basic-ops.c"

struct Node* ReverseK(struct Node* list, int k){

	struct Node* prev = NULL;
    struct Node* curr = list;
    struct Node* start = list;
    struct Node* next = NULL;

    for(int i = 0; i < k && curr != NULL; i++){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    if (next != NULL){
        start->next = ReverseK(next, k);
    }

    return prev;
}

struct Node* AltReverseK(struct Node* list, int k){

	struct Node* prev = NULL;
    struct Node* curr = list;
    struct Node* start = list;
    struct Node* next_start = NULL;
    struct Node* next = NULL;
    int i;

    for(i = 0; i < k && curr != NULL; i++){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    start->next = next;
    for(i = 1; i < k && next != NULL; i++){
        next = next->next;
    }
    if (next != NULL){
        next->next = AltReverseK(next->next, k);
    }

    return prev;
}

int main(){
    struct Node *start=NULL;
    int r, i;

    start = malloc(sizeof(struct Node));
    for(i = 1; i < 10; i++){
        // r = rand() % 100;
        // AppendNew(start, r);
        AppendNew(start, i);
    }
    start = ReverseK(start, 3);
    start = AltReverseK(start, 3);
    PrintList(start);

}
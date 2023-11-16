#include <stdio.h>
#include <stdlib.h>
#include "basic-ops.c"

void RemoveDuplicates(struct Node* start){

    struct Node* ptrCurr = start;
    struct Node* ptrComp, *dup;

    while (ptrCurr != NULL && ptrCurr->next != NULL){
        ptrComp = ptrCurr;

        while (ptrComp->next != NULL){
                                // ->next evita tener que almacenar un 'prev' o algo así
            if (ptrCurr->data == ptrComp->next->data){
                dup = ptrComp->next;
                // ->next = ->next->next
                ptrComp->next = ptrComp->next->next;
                free(dup);
            } else {
                ptrComp = ptrComp->next;
            }
        }
        ptrCurr = ptrCurr->next;
    }

}

int main(){
    struct Node *start=NULL;

    int r, i;
    for(int j = 0; j < 10; j++){
    	start = createList(start);
        printf("test %d:", j);
        for(i = 1; i < 100; i++){
            r = rand() % 100;
            AppendNew(start, r);
        }
        // PrintList(start);
        printf("Count: %d\n\n", Length(start));

        RemoveDuplicates(start);

        // PrintList(start);
        printf("Count: %d\n\n", Length(start));
        DeleteAll(&start);
    }
}
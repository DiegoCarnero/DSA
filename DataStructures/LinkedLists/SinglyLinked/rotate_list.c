#include <stdio.h>
#include <stdlib.h>
#include "basic-ops.c"

void RotateBy(struct Node** start, int k){

    int i, n;
    int length = Length((*start));
    n = length - k;
    n = (n < 0) ? -1 * n : n;
    struct Node* new_start, *end = (*start);

    for(i = 0; (end->next != NULL); i++){
        if(n == i + 1){
            new_start = end->next;
            end->next = NULL;
            end = new_start;
        } else {
            end = end->next;
        }
    }

    end->next = (*start);
    (*start) = new_start;

}
int main(){
    struct Node *start=NULL;

    int r, i;
    start = createList(start);
    for(i = 1; i < 6; i++){
        r = rand() % 10;
        AppendNew(start, r);
    }
    PrintList(start);

    RotateBy(&start, 2);

    PrintList(start);
}
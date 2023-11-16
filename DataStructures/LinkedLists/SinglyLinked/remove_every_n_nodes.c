#include <stdio.h>
#include "basic-ops.c"

void RemoveEveryNth(struct Node** start, int n){

    struct Node* ptr = (*start);
    int contNth = n;
    int ndx = 0;
    while (ptr != NULL){
        if(contNth == 1){
            ptr = ptr->next;
            DeleteNth(start, ndx);
            contNth = n;
        } else {
            contNth--;
            ndx++;
            ptr = ptr->next;
        }
    }
}

int main(){
    struct Node *start=NULL;

	start = createList(start);
    for(int i = 2; i < 11; i++){
        AppendNew(start, i);
    }
	PrintList(start);

    RemoveEveryNth(&start, 3);
	PrintList(start);
}
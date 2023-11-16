#include <stdio.h>
#include <stdlib.h>

struct Node2 {
    int data;
    struct Node2 *right, *down;
};

void AddDown(struct Node2** base, int ndx, int data) {


    struct Node2 *rightList = (*base);
    struct Node2 *dropList;

    for(int i = 0; (rightList->right) != NULL && (i < ndx); i++) {
        rightList = rightList->right;
    }

    dropList = rightList;

    while(dropList != NULL && dropList->down != NULL){
        dropList = dropList->down;
    }

    dropList->down = malloc(sizeof(struct Node2));
    dropList->down->data = data;

}

void AddRight(struct Node2** base, int data) {

    struct Node2 *rightList = (*base);

    while(rightList != NULL && rightList->right != NULL){
        rightList = rightList->right;
    }

    rightList->right = malloc(sizeof(struct Node2));
    rightList->right->data = data;

}

struct Node2* CollapseList(struct Node2 *base, struct Node2 *next) {

    struct Node2 *dropList = base->down;
    if(dropList == NULL){
        return base->right;
    }
    while(dropList->down != NULL){
        dropList->right = CollapseList(base->down, next);
        dropList->down = NULL;
    }
    if (dropList->right == NULL && dropList->down == NULL){
        dropList->right = next;
    }

    return dropList;

}

struct Node2* Flatten(struct Node2 *base){

    if (base->right == NULL) {
        base->right = CollapseList(base, base->right);
        base->down = NULL;
    } else {
        base->right = Flatten(base->right);
        base->right = CollapseList(base, base->right);
    }

    // base->right = Flatten(base->right);

    return base;
}

void PrintList(struct Node2* ptrHead){	// este head es una variable local en heap

	if(ptrHead==NULL)
	{
		printf("List is empty\n");
	} else {
		while(ptrHead != NULL){
			printf("%d ", ptrHead->data);
			ptrHead = ptrHead->right;
		}
	}
	printf("\n");
}

int main(){

    struct Node2* base = malloc(sizeof(struct Node2));
    /*
        5 -> 10 -> 90 -> 19 -> 28
        |    |           |     |
        V    V           V     V
        7    20          22    35
        |                |     |
        V                V     V
        8                50    40
        |                      |
        V                      V
        30                     45
    */
    base->data = 5;
    AddDown(&base, 1, 7);
    AddDown(&base, 1, 8);
    AddDown(&base, 1, 30);

    AddRight(&base, 10);
    AddDown(&base, 2, 20);

    AddRight(&base, 90);

    AddRight(&base, 19);
    AddDown(&base, 3, 22);
    AddDown(&base, 3, 50);

    AddRight(&base, 28);
    AddDown(&base, 4, 35);
    AddDown(&base, 4, 40);
    AddDown(&base, 4, 45);

    Flatten(base);

    PrintList(base);

}
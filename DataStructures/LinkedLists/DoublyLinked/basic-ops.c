#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Node
{
   int data;
   struct Node *prev;
   struct Node *next;	// en c++: Node* next;
};

void InsertNodeBefore(struct Node* a, struct Node* b){

    b->next = a;
    b->prev = a->prev;
    a->prev = b;
    if(b->prev != NULL){
        a->prev->next = b;
    }
}

void CreateBefore(struct Node* ptrNode, int data){

	struct Node* new_node = malloc(sizeof(struct Node));
	new_node->data = data;
	
    if (ptrNode == NULL) {
        ptrNode = new_node;
    } else {
        InsertNodeBefore(ptrNode, new_node);
    }
}

void InsertNodeAfter(struct Node* a, struct Node* b){

    b->prev = a;
    b->next = a->next;
    a->next = b;
    if(b->next != NULL){
        a->next->prev = b;
    }
}

void CreateAfter(struct Node* ptrNode, int data){

	struct Node* new_node = malloc(sizeof(struct Node));
	new_node->data = data;
	
    if (ptrNode == NULL) {
        ptrNode = new_node;
    } else {
        InsertNodeAfter(ptrNode, new_node);
    }
}

void AppendNew(struct Node* ptrNode, int data){

	while(ptrNode->next != NULL){
		ptrNode = ptrNode->next;
	}

	CreateAfter(ptrNode, data);
}

int Length(struct Node* ptrHead){
	int cont = 0;
	while(ptrHead != NULL){
		ptrHead = ptrHead->next;
		cont++;
	}

	return cont;

}

void Reverse(struct Node** ptrNode){

   struct Node* current = (*ptrNode);
   struct Node* prev = NULL;
   struct Node* next = NULL;
   while (current != NULL) {
       next = current->next;
       current->next = prev;
       current->prev = next;
       prev = current;
       current = next;
   }
   *ptrNode = prev;

}

void DeleteNth(struct Node** start, int pos){

	struct Node* ptrNode = *start;
	struct Node* prevNode = *start;
	struct Node* temp;
	int i;
	for(i = 0; i < pos; i++){
		if (i >= 1){
			prevNode = ptrNode;
		}
		ptrNode = ptrNode->next;
	}
	if(i == 0){
		temp = *start;
		*start = (*start)->next;
		free(temp);
	} else {
		prevNode->next = ptrNode->next;
        if (ptrNode->next != NULL) {
		    ptrNode->next->prev = prevNode;
        }
		free(ptrNode);
	}

}

void DeleteAll(struct Node** start){

    struct Node *current = (*start);
    struct Node *next;

	while (current != NULL)
    {
       next = current->next;
       free(current);
       current = next;
    }

    *start = NULL;
}

void Swap(struct Node** start, int data_a, int data_b){

	struct Node* prevA, *currA = *start;
    struct Node* nextA = currA->next;
	struct Node* prevB, *currB = *start;
    struct Node* nextB = currB->next;

	while (currA && currA->data != data_a){
		prevA = currA;
		currA = currA->next;
		if(currA != NULL){
            nextA = currA->next;
        }
	}
	
	while (currB && currB->data != data_b){
		prevB = currB;
		currB = currB->next;
		if(currB != NULL){
            nextB = currB->next;
        }
	}

	// si prev == NULL entonces curr es head
	if (prevA != NULL){
		prevA->next = currB;
        nextA->prev = currB;
        currB->prev = prevA;
        currB->next = nextA;
	} else {
		*start = currB;
	}

	if (prevB != NULL){
		prevB->next = currA;
        nextB->prev = currA;
        currA->prev = prevB;
        currA->next = nextB;
	} else {
		*start = currA;
	}

}

void PrintList(struct Node* ptrHead){	// este head es una variable local en heap

	if(ptrHead==NULL)
	{
		printf("List is empty\n");
	} else {
		while(ptrHead != NULL){
			printf("%d ", ptrHead->data);
			ptrHead = ptrHead->next;
		}
	}
	printf("\n");
}


int main(){
    struct Node *start = malloc(sizeof(struct Node));
	start->data = 1;
    
	CreateAfter(start, 2);
    AppendNew(start, 3);
    AppendNew(start, 5);
    AppendNew(start, 7);
	PrintList(start);
    Reverse(&start);
    PrintList(start);
    // DeleteNth(&start, 3);
    Swap(&start, 2, 5);
    PrintList(start);
}
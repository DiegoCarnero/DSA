#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Node
{
   int data;
   struct Node *next;	// en c++: Node* next;
};

struct Node *head;

struct Node* InsertAtBeginning_1(int data){
	struct Node* temp = malloc(sizeof(struct Node));
	temp->data = data;
	temp->next = head;
/*
	if(head != NULL){
		temp->next = head;
	} else {
		head = temp;
	}
*/
	return temp;

}

struct Node* InsertAtBeginning_2(struct Node* ptrHead, int data){
	struct Node* temp = malloc(sizeof(struct Node));
	temp->data = data;
	temp->next = ptrHead;	// ya se encarga de if head == null
	ptrHead = temp;

	return ptrHead;
}

void InsertAtBeginning_3(struct Node** ptrHead, int data){

	struct Node* temp = malloc(sizeof(struct Node));
	temp->data = data;
	temp->next = *ptrHead;	// ya se encarga de if head == null
	*ptrHead = temp;
}

void CreateAfter(struct Node* ptrNode, int data){

	struct Node* new_node = malloc(sizeof(struct Node));
	new_node->data = data;
	    
	if (ptrNode == NULL) {
        ptrNode = new_node;
    } else {

		new_node->next = ptrNode->next;

		ptrNode->next = new_node;
	}

}

void InsertAfter(struct Node* a, struct Node* b){

	b->next = a->next;
	a->next = b;

}

void AppendNew(struct Node* ptrNode, int data){

	while(ptrNode->next != NULL){
		ptrNode = ptrNode->next;
	}

	CreateAfter(ptrNode, data);

}

bool Contains(struct Node* ptr, int data){

    while (ptr != NULL) {
        if (ptr->data == data){
            return true;
		} else {
        	ptr = ptr->next;
		}
    }
    return false;
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

	struct Node* prev = NULL;
    struct Node* curr = *ptrNode;
    struct Node* next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *ptrNode = prev;

}

void DeleteNth(struct Node** start, int pos){

	struct Node* ptrNode = *start;
	struct Node* prev = *start;
	struct Node* temp;
	int i;
	for(i = 0; i < pos; i++){
		if (i >= 1){
			prev = ptrNode;
		}
		ptrNode = ptrNode->next;
	}
	if(i == 0){
		temp = *start;
		*start = (*start)->next;
		free(temp);
	} else {
		printf("prev: %d ptrNode: %d\n", prev->data, ptrNode->data);
		prev->next = ptrNode->next;
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
	struct Node* prevB, *currB = *start;
	struct Node* temp;

	while (currA && currA->data != data_a){
		prevA = currA;
		currA = currA->next;
	}
	
	while (currB && currB->data != data_b){
		prevB = currB;
		currB = currB->next;
	}

	// si prev == NULL entonces curr es head
	if (prevA != NULL){
		prevA->next = currB;
	} else {
		*start = currB;
	}

	if (prevB != NULL){
		prevB->next = currA;
	} else {
		*start = currA;
	}

	temp = currB->next;
	currB->next = currA->next;
	currA->next = temp;

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

void PrintGlobal(){
	struct Node* temp = head;

	// solo se modifica la variable temp, no los nodos en la lista
	while(temp != NULL){
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

struct Node *createList(struct Node *start)
{
	int i,n,data;

	printf("Enter the number of Nodes : ");
	scanf("%d",&n);
	
	if(n==0)
		return start;

	printf("Enter the first element to be inserted : ");
	scanf("%d",&data);
	// start = InsertAtBeginning_2(start, data);
	InsertAtBeginning_3(&start, data);

	for(i=2; i<=n; i++)
	{
		printf("Enter the next element to be inserted : ");
		scanf("%d",&data);
		// start = InsertAtBeginning_2(start,data);
		InsertAtBeginning_3(&start, data);
	}
	return start;
}
/*
int main(){
    struct Node *start=NULL;

	start = createList(start);
	printf("\n");
	PrintList(start);
	CreateAfter(start, 2);
	struct Node* node = malloc(sizeof(struct Node));
	node->data = 10;
	InsertAfter(start, node);

	AppendNew(start, 5);
	AppendNew(start, 3);
	AppendNew(start, 7);

	printf("\n");
	PrintList(start);
	printf("\nContiene 5? %d", Contains(start, 5));
	printf("\nLength: %d\n", Length(start));

	Reverse(&start);
	PrintList(start);
	printf("\n");
	// DeleteAll(&start);
	DeleteNth(&start, 3);
	PrintList(start);
}*/
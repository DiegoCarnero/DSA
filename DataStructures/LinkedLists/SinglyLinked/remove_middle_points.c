#include <stdio.h>
#include <stdlib.h>

struct Node3 {
    int x, y;
    struct Node3 *next;
};

void PrintList(struct Node3* ptrHead);

void AppendNew(struct Node3* ptrNode, int x, int y){

	while(ptrNode->next != NULL){
		ptrNode = ptrNode->next;
	}

	struct Node3* new_node = malloc(sizeof(struct Node3));
    new_node->x = x;
    new_node->y = y;
    ptrNode->next = new_node;
}

void deleteNode(struct Node3 *head, struct Node3 *Next)
{
    head->next = Next->next;
    Next->next = NULL;
    free(Next);
}

struct Node3* deleteMiddle(struct Node3 *head)
{
    // If only one node or no node...Return back
    if (head==NULL || head->next ==NULL || head->next->next==NULL)
        return head;
 
    struct Node3* Next = head->next;
    struct Node3 *NextNext = Next->next ;
 
    // Check if this is a vertical line or horizontal line
    if (head->x == Next->x)
    {
        // Find middle nodes with same x value, and delete them
        while (NextNext !=NULL && Next->x==NextNext->x)
        {
            head->next = Next->next;
            Next->next = NULL;
            free(Next);
 
            // Update Next and NextNext for next iteration
            Next = NextNext;
            NextNext = NextNext->next;
        }
    }
    else if (head->y==Next->y) // If horizontal line
    {
        // Find middle nodes with same y value, and delete them
        while (NextNext !=NULL && Next->y==NextNext->y)
        {
            head->next = Next->next;
            Next->next = NULL;
            free(Next);
 
            // Update Next and NextNext for next iteration
            Next = NextNext;
            NextNext = NextNext->next;
        }
    }
    else  // Adjacent points must have either same x or same y
    {
        puts("Given linked list is not valid");
        return NULL;
    }
 
    // Recur for next segment
    deleteMiddle(head->next);
 
    return head;
}

void PrintList(struct Node3* ptrHead){	// este head es una variable local en heap

	if(ptrHead==NULL)
	{
		printf("List is empty\n");
	} else {
		while(ptrHead->next != NULL){
			printf("(%d, %d)->", ptrHead->x, ptrHead->y);
			ptrHead = ptrHead->next;
		}
        printf("(%d, %d)", ptrHead->x, ptrHead->y);
	}
	printf("\n");
}

int main(){
    struct Node3 *start= malloc(sizeof(struct Node3));
    start->x = 0;
    start->y = 10;/*
    AppendNew(start, 0, 5);
    AppendNew(start, 0, 10);
    AppendNew(start, 1, 10);
    AppendNew(start, 5, 10);
    AppendNew(start, 7, 10);
    AppendNew(start, 7, 5);
    AppendNew(start, 20, 5);
    AppendNew(start, 40, 5);
*/

    AppendNew(start, 1,10);
    AppendNew(start, 5,10);
    AppendNew(start, 7,10);
    AppendNew(start, 7,5);
    AppendNew(start, 20,5);
    AppendNew(start, 40,5);

	PrintList(start);
	deleteMiddle(start);
	PrintList(start);
}
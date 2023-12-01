#include "basic-ops.c"

// probablemente podría optimizarse si nos aseguramos que Contains solo usa la lista más corta ya que esa es la que se recorrerá varias veces

struct Node* Union(struct Node* list1, struct Node* list2){

    struct Node* result = NULL;
    struct Node* temp = list1;

    while(temp != NULL){
        InsertAtBeginning_3(&result, temp->data);
        temp = temp->next;
    }

    temp = list2;
    while(temp != NULL){
        if(!Contains(list1, temp->data)){
            AppendNew(result, temp->data);
        }
        temp = temp->next;
    }

    return result;
}

struct Node* Intersection(struct Node* list1, struct Node* list2){

    struct Node* result = NULL;
    struct Node* temp = list1;

    while(temp != NULL){
        if(Contains(list2, temp->data)){
            InsertAtBeginning_3(&result, temp->data);
        }
        temp = temp->next;
    }
    return result;
}

int main(){

    struct Node* list1 = InsertAtBeginning_1(10);

    AppendNew(list1, 15);
    AppendNew(list1, 4);
    AppendNew(list1, 20);
    
    struct Node* list2 = InsertAtBeginning_1(8);

    AppendNew(list2, 4);
    AppendNew(list2, 2);
    AppendNew(list2, 10);

    PrintList(list1);
    PrintList(list2);
    printf("\n");

    struct Node* result = Union(list1, list2);
    printf("Union: ");
    PrintList(result);
    result = Intersection(list1, list2);
    printf("Intersection: ");
    PrintList(result);
}
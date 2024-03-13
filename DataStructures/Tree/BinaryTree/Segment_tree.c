#include <stdio.h>
#include <stdlib.h>

void gen_sums(int tree[], int start, int end){

    int sum;

    if(start == end - 1){
        // tree[0] = tree[start] + tree[end-1];
        return;
    }

    for(int i = start; i + 1 < end; i+=2){
        if(i + 1 < end){
            sum = tree[i] + tree[i+1];
        } else{
            sum = tree[i];
        }
        tree[i/2] = sum;
    }
    gen_sums(tree, start / 2, start);

}

void build(int tree[], int arr[], int size){

    for(int i=0; i < size; i++){
        tree[i + (size - 1)] = arr[i];
    }

    gen_sums(tree, size - 1, 2 * size);
    // for (int i = size - 1; i > 0; --i)
    //     tree[i] = tree[i<<1] + tree[i<<1|1];

}

void update(int tree[], int size, int ndx, int new_val){

    // 1. comprobar si indice es par o impar
    //      0
    //    |  |
    //    1  2

    int sibling_val = 0;

    // 2. coger el nodo hermano y sumar
    if(ndx % 2 == 0){
        sibling_val = tree[ndx-1];
    } else {
        if(ndx+1 < size){
            sibling_val = tree[ndx+1];
        }
    }

    int sum = sibling_val + new_val;
    tree[ndx] = new_val;

    // 3. Volver a llamar update con new_val=suma y ndx = ndx / 2
    if(ndx > 2){
        update(tree, size, ndx / 2, sum);
    } else {
        tree[0] = tree[1] + tree[2];
    }

}
void query(){}

void Print(int arr[], int size) 
{ 
    int i, j = 2;
    printf("%d\n", arr[0]);
    for (i=1; i < size; i++){
        printf("%d ", arr[i]);
        if(i == j){
            printf("\n");
            j = 2*j + j;
        }
    }
    
    printf("\n"); 
}  


int main(){

    // int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    int arr[7] = {5,8,7,2,10,2,2};
    // int arr[8] = {8, 6, 9, 1, 3, 4, 6, 8};
    int n = sizeof(arr)/sizeof(arr[0]); 
    int tree[13];

    build(tree, arr, n);

    Print(tree, 2 * n - 1);
    printf("\n");
    update(tree, 2*n, 11, 11);

    Print(tree, 2 * n - 1);
}


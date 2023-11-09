#include<stdio.h> 
#include <stdlib.h>

// malo porque no sabes si x es un array estático
#if !defined(ARRAY_SIZE)
    #define ARRAY_SIZE(x) (sizeof((x)) / sizeof((x)[0]))
#endif

int cmpfunc (const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}

void SortArray(int arr[], int length)
{
    qsort(arr, length, sizeof(int), cmpfunc);
}


// Time Complexity: O(N * d)
// Auxiliary Space: O(1)
void Rotate_simple(int arr[], int size, int rotate_by)
{
    // otras opciones es array auxiliar, copias arr a partir de i = rotate_by, luego añades al final lo que hay antes de i = rotate_by
    int p = 1;
    int last;
    while(p <= rotate_by){
        last = arr[0];
        for(int i = 0; i < size - 1; i++){
            arr[i] = arr[i+1];
        }
        arr[size - 1] = last;
        p++;
    }
}

// array sent as a parameter to a function is treated as a pointer, so sizeof will return the pointer's size, instead of the array's.
int IndexOf(int arr[], int value, int size)
{
    int i;
    for (i=0; i < size; i++)
        if(arr[i] == value)
            return i;
    return -1;    
}

int Insert(int arr[], int capacity, int length, int new, int pos)
{
    if (pos >= capacity){
        printf("Cant insert at \"%d\"", pos);
        return length;
    }

    for (int i = length - 1; i >= pos; i--)
        arr[i + 1] = arr[i];
 
    arr[pos] = new;
    return length + 1;
}

int Delete(int arr[], int length, int key)
{
    int pos = IndexOf(arr, key, length);
 
    if (pos == -1) {
        printf("Element not found");
        return length;
    }

    int act, prev = arr[length -1];
    for (int i = length - 2; i >= pos; i--)
    {
        act = arr[i];
        arr[i] = prev;
        prev = act;
    }
 
    return length - 1;
}

void Reverse(int arr[], int start, int end) 
{ 
    int temp; 
    while (start < end) 
    { 
        temp = arr[start];    
        arr[start] = arr[end]; 
        arr[end] = temp; 
        start++; 
        end--; 
    }    
}      

void PrintArray(int arr[], int size) 
{ 
  int i; 
  for (i=0; i < size; i++) 
    printf("%d ", arr[i]); 
  
  printf("\n"); 
}  
  

int main()  
{ 
    // int arr[] = {2, 3, 4, 5, 6, 7}; 
    // int n = sizeof(arr) / sizeof(arr[0]);
    // PrintArray(arr, n); 
    // Reverse(arr, 0, n-1); 
    // printf("Reversed array is \n"); 
    // PrintArray(arr, n);
    // printf("Index of \"%d\": %d\n", 3, IndexOf(arr, 3, n));
    // Rotate_simple(arr, n, 2);
    // PrintArray(arr, n);
    int arr[10] = {7, 3, 4, 2, 6, 1};
    int length = 6;
    // int size = sizeof(arr) / sizeof(arr[0]);
    // printf("%d\n", length);
    // PrintArray(arr, length);
    // length = Insert(arr, size, length, 9, 3);
    // PrintArray(arr, length);
    // length = DeleteElement(arr, length, 2);
    // PrintArray(arr, length);
    SortArray(arr, length);
    PrintArray(arr, length);

    return 0; 
} 
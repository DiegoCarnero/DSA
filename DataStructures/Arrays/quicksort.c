#include <stdio.h>
#include <time.h>
#include "basic-ops.c"

/*
Quicksort: algoritmo de tipo 'divide and conquer'.
1. Array se divide en subarrays a partir de un elemento pivote.
   Elementos a la izq are menores que el pivote y a la drcha son mayores
2. Lo mismo con los subarrays. Recursivo
3. Se convinan los elementos en un solo array.
- Se coje:
    * el último elemento como pivote, P
    * el principio del array, A
  Y recorremos el array.
- Encontramos un elemento B menor que el pivote, se intercambia con A.
- Ahora el 2º elmento del array será A, continuamos desde donde estaba el elemento B antes del swap
- Swapeamos el pivote con A más reciente.
- Repetimos con los elementos desde la nueva posición del pivote hasta el final
*/

int particion(int arr[], int low, int high) {
    int pivot = arr[high];  
    int i = (low - 1);
  
    for (int j = low; j <= high - 1; j++) {  
        if (arr[j] < pivot) {  
            i++;  
            swap(&arr[i], &arr[j]);  
        }  
    }  
    swap(&arr[i + 1], &arr[high]);  
    return (i + 1);  
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {  
        int pi = particion(arr, low, high);
        quickSort(arr, low, pi - 1);  
        quickSort(arr, pi + 1, high);  
    }  
}  
 
int main() {
    clock_t start, end;
    double cpu_time_used1, cpu_time_used2;

    int arr1[] = {61, 55, 48, 24, 74, 95, 32, 19, 4, 12, 44, 94, 64, 69, 51, 65, 79, 93, 26, 53, 28, 85, 21, 56, 38, 3, 13, 33, 82, 73, 87, 1, 31, 36, 96, 37, 20, 78, 60, 27, 2, 77, 6, 98, 22, 41, 89, 81, 10, 67, 9, 100, 43, 71, 40, 35, 88, 50, 11, 47, 54, 68, 66, 52, 45, 7, 5, 97, 80, 63, 18, 90, 62, 58, 34, 16, 91, 23, 39, 92, 30, 14, 42, 76, 15, 70, 8, 25, 84, 83, 57, 46, 59, 49, 72, 17, 29, 75, 99, 86};
    int arr2[] = {61, 55, 48, 24, 74, 95, 32, 19, 4, 12, 44, 94, 64, 69, 51, 65, 79, 93, 26, 53, 28, 85, 21, 56, 38, 3, 13, 33, 82, 73, 87, 1, 31, 36, 96, 37, 20, 78, 60, 27, 2, 77, 6, 98, 22, 41, 89, 81, 10, 67, 9, 100, 43, 71, 40, 35, 88, 50, 11, 47, 54, 68, 66, 52, 45, 7, 5, 97, 80, 63, 18, 90, 62, 58, 34, 16, 91, 23, 39, 92, 30, 14, 42, 76, 15, 70, 8, 25, 84, 83, 57, 46, 59, 49, 72, 17, 29, 75, 99, 86};
    int size = sizeof(arr1) / sizeof(arr1[0]);  
    // PrintArray(arr1, size);

    start = clock();
    // empezamos con los valores en los extremos
    quickSort(arr1, 0, size - 1);
    end = clock();
    cpu_time_used1 = ((double) (end - start)) / CLOCKS_PER_SEC;

    start = clock();
    // empezamos con los valores en los extremos
    SortArray(arr2, size);
    end = clock();
    cpu_time_used2 = ((double) (end - start)) / CLOCKS_PER_SEC;
    
    printf("\nTime taken handmade: %f\nTime taken builtin: %f\n", cpu_time_used1, cpu_time_used2);

    // PrintArray(arr1, size);
    return 0;  
}  
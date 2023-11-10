#include <stdio.h>
/*
PARA ARRAYS ORDENADOS (en este caso de menor a mayor)
En lugar de comparar una posición del array a todas las demás, comprobamos los valores en los extremos
Si la suma es > que X, desplazamos el puntero del extremo drcho hacia la izq.
Si la suma es < que X, desplazamos el puntero del extremo izq hacia la drcha.
*/
int isPairSum(int  arr[], int N, int X) 
{
    int i = 0; 

    int j = N - 1; 
  
    while (i < j) 
    {
        if ( arr[i] +  arr[j] == X) {
            printf("%d + %d = %d", arr[i],  arr[j], X);
            return 1;
        }
        else if ( arr[i] +  arr[j] < X) 
            i++; 
        else
            j--; 
    } 
    return 0; 
} 

int main() 
{
    int arr[] = { 3, 5, 9, 2, 8, 10, 11 }; 
    int val = 17; 
    int size = sizeof(arr) / sizeof(arr[0]); 
    
    isPairSum(arr, size, val);
  
    return 0; 
}
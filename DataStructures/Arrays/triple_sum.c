#include <stdio.h>
#include <stdlib.h>
#include "basic-ops.c"

/*
Combinación del método naive y two pointers. Fijamos el primer valor del array y usamos two pointers en los restantes
*/
int SumOfThree(int  arr[], int size, int sum)
{
    int l, r;

    qsort(arr, size, sizeof(int), cmpfunc);

    for (int i = 0; i < size - 2; i++)
    {
        l = i + 1;
        r = size - 1;
        while (l < r) {
            if ( arr[i] +  arr[l] +  arr[r] == sum) {
                printf("%d + %d + %d = %d\n",  arr[i],  arr[l], arr[r], sum);
                return 1;
            }
            else if ( arr[i] +  arr[l] +  arr[r] < sum){
                l++;
            }else{
                r--;
            }
        }
    }

    return 0;
}

int main()
{
    int  arr[] = { 1, 4, 45, 6, 10, 8 };
    int sum = 22;
    int size = sizeof(arr) / sizeof( arr[0]);
    SumOfThree(arr, size, sum);
    return 0;
}
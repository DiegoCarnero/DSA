#include "basic-ops.c"
# include <stdio.h>

// TODO probar con binary search
int SmallestSumWithSub(int arr[], int size, int x)
{
    int min_len = size + 1;
    int start_final, end_final;
    for (int start=0; start<size; start++)
    {
        int curr_sum = arr[start];
        if (curr_sum > x){
            printf("[");
            PrintSlice(arr, 0, 1);
            return 1;
        }

        for (int end=start+1; end<size; end++)
        {
            curr_sum += arr[end];

            if (curr_sum > x && (end - start + 1) < min_len){
                min_len = (end - start + 1);
                start_final = start;
                end_final = end + 1;
            }
        }
    }

    printf(">> ");
    PrintSlice(arr, start_final, end_final);
    return min_len;
}
 
/* Driver program to test above function */
int main()
{
    int arr1[] = {1, 4, 45, 6, 10, 19};
    int x = 51;
    int size = sizeof(arr1)/sizeof(arr1[0]);
    int res1 = SmallestSumWithSub(arr1, size, x);
    printf("%d\n", res1);
 
    int arr3[] = {1, 11, 100, 1, 0, 200, 3, 2, 1, 250};
    int n3 = sizeof(arr3)/sizeof(arr3[0]);
    x  = 280;
    int res3 = SmallestSumWithSub(arr3, n3, x);
    
    printf("%d\n", res3);
 
    return 0;
}

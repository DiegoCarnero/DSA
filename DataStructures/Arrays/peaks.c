#include "basic-ops.c"
#include <stdio.h>

void peaks(int arr[], int size)
{
    int peaks[10] = {0};
    PrintArray(peaks, size);
    if(size < 3){
        return;
    }

    int peak_indices = 0;
    for( int i = 1; i < size - 1; i++){
        if(arr[i-1] < arr[i] && arr[i] > arr[i+1]){
            peaks[peak_indices] = i;
            peak_indices++;
        }
    }

    printf("Peaks are \n");
    for (int j = 0; j < peak_indices; j++){
        printf("%d ", arr[peaks[j]]);
    }
    printf("at ");
    PrintArray(peaks, peak_indices);

    return;
}
 
/* Driver program to test above function */
int main()
{
    
    int arr[] = {10, 20, 15, 2, 23, 90, 67};
    int size = sizeof(arr)/sizeof(arr[0]);
    PrintArray(arr, size);
    peaks(arr, size);

    return 0;
}

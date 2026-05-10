// Solution to Q7.3 on Assignment 4

#include <stdio.h>

void insertionSort(int arr[], int size) {
    for(int k=1; k<size; k++) {
        int temp = arr[k];
        int j = k-1;
        while(temp <= arr[j] && j>=0) {
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = temp;
    }
}

void merge(int arr[], int left, int mid, int right) {
    int temp[right+1]; // temp array
    int i=left;
    int j=mid+1;
    int index = 0;

    while(i <= mid && j <= right) {
        if(arr[i] < arr[j])
            temp[index++] = arr[i++];
        else
            temp[index++] = arr[j++];
    } 

    if (i > mid)
        while(j <= right) temp[index++] = arr[j++];
    else
        while(i <= mid) temp[index++] = arr[i++];

    // Copy temp to arr
    for (int k=0; k<index; arr[k+left] = temp[k], k++);
}

void mergeSortHelper(int arr[], int left, int right, int k) {
    if (left - right <= k)
        insertionSort(arr, right+1);
    else {
        int mid = (left + right) / 2;
        mergeSortHelper(arr, left, mid, k);
        mergeSortHelper(arr, mid+1, right, k);
        merge(arr, left, mid, right);
    }
}


int main(void) {
    int sort[] = { 39, 9, 81, 45, 90, 27, 72, 18 };
    int size = 8;
    
    
    printf("\nUnsorted : [");
    for (int i=0; i<size; printf("%d ", sort[i]), i++);
    printf("]");
    
    
    mergeSortHelper(sort, 0, size-1, 3);


    printf("\nSorted : [");
    for (int i=0; i<size; printf("%d ", sort[i]), i++);
    printf("]");

    return 1;
}
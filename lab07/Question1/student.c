#include <stdbool.h>
/*
Question 1: Bubble Sort

Description:
Implement two versions of bubble sort for an integer array.

1. bubbleSort:
   Implement the basic bubble sort algorithm.
   Repeatedly compare adjacent elements and swap them if they are
   in the wrong order. After each pass, the largest unsorted element
   should move to its correct position.

2. bubbleSortOptimized:
   Implement an improved version of bubble sort.
   This version should stop early if a full pass completes without
   any swaps, which means the array is already sorted.

Both functions should sort the array in ascending order.

Example:
Input:  [5, 1, 4, 2, 8]
Output: [1, 2, 4, 5, 8]

Notes:
- If the array is empty or has only one element, do nothing.
- You may write a helper function such as swap(...) if you want.
*/

void swap(int *a, int*b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int size) {
    (void)arr;
    (void)size;

    if (size >= 2) {
        for (int i=0; i<size; i++) {
            for(int j=0; j<size-i; j++) {
                if(arr[j] > arr[j+1]) 
                    swap(arr+j, arr+j+1);
            }
        }
    }
}

void bubbleSortOptimized(int arr[], int size) {
    // TODO: implement optimized bubble sort with early stopping
    (void)arr;
    (void)size;

    int swaps = 0;
    if (size >= 2) {
        for (int i=0; i<size; i++) {
            if(i > 1 && swaps == 0) break;
            for(int j=0; j<size-i; j++) {
                if(arr[j] > arr[j+1]) {
                    swap(arr+j, arr+j+1);
                    swaps++;
                }
            }
        }
    }
}


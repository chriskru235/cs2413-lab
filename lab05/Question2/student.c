/*
Question 2: Kth Largest Element in an Array

Description:
Given an integer array nums and an integer k, return the kth largest
element in the array.

Note that it is the kth largest element in sorted order, not the kth
distinct element.

For this lab, you should solve the problem using a heap-based idea.

Function:
int findKthLargest(int* nums, int numsSize, int k);

Notes:
- You may assume 1 <= k <= numsSize.
- Repeated values still count.
- A min-heap of size k is a good way to solve this efficiently.

Example 1:
Input:  nums = [3, 2, 1, 5, 6, 4], k = 2
Output: 5

Example 2:
Input:  nums = [3, 2, 3, 1, 2, 4, 5, 5, 6], k = 4
Output: 4

Hint:
Keep only the k largest elements seen so far in a min-heap.
The root of that heap will be the kth largest element.
*/

#include <stdlib.h>

static void swap(int* a, int* b);
static void heapifyDown(int *heap, int size, int index);

/*
Return the kth largest element in nums.
*/
int findKthLargest(int* nums, int numsSize, int k) {
    for (int i=(numsSize/2) - 1; i >= 0; i--) // Initial heap
        heapifyDown(nums, numsSize, i);

    for (int i = numsSize - 1; i > 0; i--) { // Reduced heap
        swap(nums, nums+i);
        heapifyDown(nums, i, 0);
    }

    return nums[numsSize - k];
}

static void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

static void heapifyDown(int *heap, int size, int index) {
    int largest = index; // root node index
    int left = 2 * index + 1; // left child node index
    int right = 2 * index + 2; // right child node index

    if (left < size && heap[left] > heap[largest]) largest = left;
    if (right < size && heap[right] > heap[largest]) largest = right;

    if (largest != index) { // largest is not the root
        swap(heap + index, heap + largest);
        heapifyDown(heap, size, largest);
    }
}
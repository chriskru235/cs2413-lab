#include "two_sum_sorted.h"

int two_sum_sorted(const int* nums, int n, int target, int* out_i, int* out_j) {
    if (!nums || !out_i || !out_j || n < 2) return 0;

    // TODO: implement rwo sum solution for sorted arrays.
    int i=0, j=n-1;
    while(j > i) {
		int sum = nums[i] + nums[j];
		if(sum > target) j--; // sum is larger than target
		else if(sum < target) i++; // sum is smaller than target
		else if(sum == target) {		// sum is target
			*out_i = i;
			*out_j = j;
			return 1;
		}
    }
    return 0; // j == i
}
// think about the time complexity and space complexity of your solution


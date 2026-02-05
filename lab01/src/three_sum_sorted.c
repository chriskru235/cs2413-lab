#include "three_sum_sorted.h"

int three_sum_zero_sorted_one(const int* nums, int n, int* out_i, int* out_j, int* out_k) {
    
    // implement your code here
    	int i=0;
    	// (j = L; k = R)
	for(;i<n;i++) {
		int j=i+1, k=n-1;
		while(k > j) {
			int sum = nums[i] + nums[j] + nums[k];
			if(sum < 0) j++; // L is too low
			else if(sum > 0) k--; // R is too high
			else { // sum is equal to 0
				*out_i = i;
				*out_j = j;
				*out_k = k;
				return 1;
			}
		} 
	}

    return 0;
}

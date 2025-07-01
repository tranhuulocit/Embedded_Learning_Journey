#include <stdio.h>

int removeDuplicates(int* nums, int numsSize) {
	if (numsSize == 0) {
		return 0;
	}
	int i, j;
	for (j = 1; j < numsSize; j++) {
		if (nums[j] != nums[i]) {
			i++;
			nums[i] = nums[j];
		}
	}
	return i+1;
}

int main () {
	int nums[] = {1, 1, 2};
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	
	printf("--EX1--\n");
	printf("Input array: [");
	for (int k = 0; k < numsSize; k++) {
		printf("%d%s", nums[k], (k == numsSize - 1) ? "" : ",");
	}
	printf("]\n");
	
	int k_result = removeDuplicates(nums, numsSize);
	
	printf("Output: k = %d, nums = [", k_result);
	for (int k = 0; k < k_result; k++) {
		printf("%d%s", nums[k], (k == k_result - 1) ? "" : ",");
	}
	for (int k = k_result; k < numsSize; k++) {
		printf("_%s", (k == numsSize - 1) ? "" : ",");
	}
	printf("]\n");
	
	return 0;
}

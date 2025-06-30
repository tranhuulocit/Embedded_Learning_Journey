#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
	int* result = (int*)malloc(2 * sizeof(int));
	
	if (result == NULL) {
		*returnSize = 0;
		return NULL;
	}
	
	*returnSize = 2;
	
	int i, j;
	for (i = 0; i < numsSize; i++) {
		for (j = i + 1; j < numsSize; j++) {
			if (nums[i] + nums[j] == target) {
				result[0] = i;
				result[1] = j;
				return result;
			}
		}
	}
	free(result);
	*returnSize = 0;
	return NULL;
}

int main() {
	int nums[] = {2, 3, 4, 5, 6, 7, 11, 18}
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	int target = 9;
	int returnSize;
	
	return 0;
}

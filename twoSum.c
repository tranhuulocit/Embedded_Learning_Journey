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
		for (j = i + 1; j< numsSize; j++){
			if(nums[i] + nums[j] == target) {
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

int main (){
	//ex1
	int nums1[] = {2, 7, 11, 15};
	int numsSize1 = sizeof(nums1) / sizeof(nums1[0]);
	int target1 = 9;
	int returnSize1;
	
	printf("--EX1--\n");
	printf("Input: nums = [2, 7, 11, 15], target = 9\n");
	
	int* result1 = twoSum(nums1, numsSize1, target1, &returnSize1);
	
	if (result1 != NULL && returnSize1 == 2) {
		printf("Output: [%d,%d]\n", result1[0], result1[1]);
	} else {
		printf("No solution found or memory allocation failed for example 1.\n");
		
	}
	
	//giai phong bo nho
	free(result1);
	result1 = NULL;
	
	return 0;
}






















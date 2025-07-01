#include <stdio.h>

int removeElement(int* nums, int numsSize, int val) {
	int left = 0;
	int right = numsSize - 1;

	while (left <= right) {
		if (nums[left]  == val) {
			nums[left] = nums[right];
			right--;
		} else {
			left++;
		}
	}
	return left;
}

int main() {
	//Ex1
	int nums1[] = {3, 2, 2, 3};
	int val1 = 3;
	int numsSize1 = sizeof(nums1) / sizeof(nums1[0]);
	 
	printf ("--Ex1--\n");
	printf("Input: nums = [");
	for (int k = 0; k < numsSize1; k++) {
		printf("%d%s", nums1[k], (k == numsSize1 - 1) ? "" : ",");
	}
	printf("], val = %d\n", val1);
	
	int k1 = removeElement(nums1, numsSize1, val1);
	
	printf("Output: k = %d, nums = [", k1);
	for (int k = 0; k < k1; k++) {
		printf("%d%s", nums1[k], (k == k1 - 1) ? "" : ",");
	}
	printf("]\n\n");
	
	//Ex2
	int nums2[] = {0, 1, 2, 2, 3, 0, 4, 2};
    int val2 = 2;
    int numsSize2 = sizeof(nums2) / sizeof(nums2[0]);

    printf("--- Example 2 ---\n");
    printf("Input: nums = [");
    for (int k = 0; k < numsSize2; k++) {
        printf("%d%s", nums2[k], (k == numsSize2 - 1) ? "" : ",");
    }
    printf("], val = %d\n", val2);

    int k2 = removeElement(nums2, numsSize2, val2);

    printf("Output: k = %d, nums = [", k2);
    for (int k = 0; k < k2; k++) {
        printf("%d%s", nums2[k], (k == k2 - 1) ? "" : ",");
    }
    for (int k = k2; k < numsSize2; k++) {
        printf("_%s", (k == numsSize2 - 1) ? "" : ",");
    }
    printf("]\n\n");

	return 0;
}

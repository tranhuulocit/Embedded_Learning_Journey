#include <stdio.h>

int max(int a, int b) {
	return (a > b) ? a : b;
}

int min(int a, int b) {
	return (a < b) ? a : b;
}

int maxArea(int* height, int heightSize) {
	int left = 0;
	int right = heightSize - 1;
	int max_water = 0;
	
	while (left < right) {
		int current_width = right - left;
		
		int current_height_limit = min(height[left], height[right]);
		
		int current_area = current_width * current_height_limit;
		
		max_water = max(max_water, current_area);
		
		if (height[left] < height[right]) {
			left++;
		} else {
			right--;
		}
	}
	
	return max_water;
}

int main() {
    // Ex1
    int height1[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int n1 = sizeof(height1) / sizeof(height1[0]);
    int result1 = maxArea(height1, n1);
    printf("Input: [");
    for (int i = 0; i < n1; i++) {
        printf("%d%s", height1[i], (i == n1 - 1) ? "" : ",");
    }
    printf("]\n");
    printf("Output: %d\n\n", result1);

    // Ex2
    int height2[] = {1, 1};
    int n2 = sizeof(height2) / sizeof(height2[0]);
    int result2 = maxArea(height2, n2);
    printf("Input: [");
    for (int i = 0; i < n2; i++) {
        printf("%d%s", height2[i], (i == n2 - 1) ? "" : ",");
    }
    printf("]\n");
    printf("Output: %d\n\n", result2);

    // Ex3
    int height3[] = {2, 3, 4, 5, 18, 17, 6};
    int n3 = sizeof(height3) / sizeof(height3[0]);
    int result3 = maxArea(height3, n3);
    printf("Input: [");
    for (int i = 0; i < n3; i++) {
        printf("%d%s", height3[i], (i == n3 - 1) ? "" : ",");
    }
    printf("]\n");
    printf("Output: %d\n\n", result3);

    return 0;
}

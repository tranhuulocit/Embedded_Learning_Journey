#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static int expandAroundCenter(char* s, int left, int right, int s_len) {
	while (left >= 0 && right < s_len && s[left] == s[right]) {
		left--;
		right++;
	}
	return right - left - 1;
}

char* longestPalindrome(char* s) {
	if (s == NULL || *s == '\0') {
		char* empty_str = (char*)malloc(sizeof(char));
		empty_str[0] = '\0';
		return empty_str;
	}
	
	int s_len = strlen(s);
	
	if (s_len == 1) {
        char* single_char_str = (char*)malloc(sizeof(char) * 2); 
        single_char_str[0] = s[0];
        single_char_str[1] = '\0';
        return single_char_str;
    }

	int start_index = 0;
	int max_length = 1;
	
	for (int i = 0; i < s_len; i++) {
        int len1 = expandAroundCenter(s, i, i, s_len);

        int len2 = expandAroundCenter(s, i, i + 1, s_len);

        int current_max_len = (len1 > len2) ? len1 : len2;

        if (current_max_len > max_length) {
            max_length = current_max_len;
            start_index = i - (max_length - 1) / 2;
        }
    }

	char* result_str = (char*)malloc(max_length + 1);
    if (result_str == NULL) {
        return NULL;
    }
    
    memcpy(result_str, s + start_index, max_length);
    result_str[max_length] = '\0';
	
	return result_str;
}

int main(){
	//Ex1
	char* s1 = "babad";
    char* result1 = longestPalindrome(s1);
    printf("Input: \"%s\"\n", s1);
    printf("Output: \"%s\"\n\n", result1);
    free(result1);
    
    //Ex2
    char* s2 = "cbbd";
    char* result2 = longestPalindrome(s2);
    printf("Input: \"%s\"\n", s2);
    printf("Output: \"%s\"\n\n", result2);
    free(result2);
    
    //Ex3
	char* s3 = "a";
    char* result3 = longestPalindrome(s3);
    printf("Input: \"%s\"\n", s3);
    printf("Output: \"%s\"\n\n", result3);
    free(result3);
    
    //Ex4
    char* s4 = "forgeeksskeegfor"; // "geeksskeeg"
    char* result4 = longestPalindrome(s4);
    printf("Input: \"%s\"\n", s4);
    printf("Output: \"%s\"\n\n", result4);
    free(result4);
    
	return 0;
}

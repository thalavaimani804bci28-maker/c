#include <string.h>

int longestValidParentheses(char* s) {
    int maxLen = 0;
    int left = 0;  // Counts '('
    int right = 0; // Counts ')'
    
    // Pass 1: Left to Right scan
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(') {
            left++;
        } else {
            right++;
        }
        
        if (left == right) {
            int currentLen = 2 * right;
            if (currentLen > maxLen) {
                maxLen = currentLen;
            }
        } else if (right > left) {
            // Invalid combination found, reset counters
            left = 0;
            right = 0;
        }
    }
    
    // Reset counters for the reverse scan
    left = 0;
    right = 0;
    int len = strlen(s);
    
    // Pass 2: Right to Left scan
    for (int i = len - 1; i >= 0; i--) {
        if (s[i] == '(') {
            left++;
        } else {
            right++;
        }
        
        if (left == right) {
            int currentLen = 2 * left;
            if (currentLen > maxLen) {
                maxLen = currentLen;
            }
        } else if (left > right) {
            // Invalid combination found, reset counters
            left = 0;
            right = 0;
        }
    }
    
    return maxLen;
}

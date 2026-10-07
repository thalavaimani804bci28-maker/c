#include <stdlib.h>

// Comparison function for qsort
int compare(const void* a, const void* b) {
    int valA = *(const int*)a;
    int valB = *(const int*)b;
    if (valA < valB) return -1;
    if (valA > valB) return 1;
    return 0;
}

int findPairs(int* nums, int numsSize, int k) {
    if (numsSize < 2) return 0;

    // Step 1: Sort the array in ascending order
    qsort(nums, numsSize, sizeof(int), compare);

    int count = 0;
    int left = 0;
    int right = 1;

    // Step 2: Use two pointers to find valid k-diff pairs
    while (left < numsSize && right < numsSize) {
        // Pointers cannot point to the same index
        if (left == right) {
            right++;
            continue;
        }

        int diff = nums[right] - nums[left];

        if (diff == k) {
            count++;
            left++;
            right++;

            // Skip duplicate values for the left pointer to ensure unique pairs
            while (left < numsSize && nums[left] == nums[left - 1]) {
                left++;
            }
        } 
        else if (diff < k) {
            // Difference is too small; increase the right pointer to get a larger value
            right++;
        } 
        else {
            // Difference is too large; increase the left pointer to reduce the gap
            left++;
        }
    }

    return count;
}

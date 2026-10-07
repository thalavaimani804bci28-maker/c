#include <stdio.h>
#include <stdlib.h>

int magicalString(int n) {
    if (n <= 0) return 0;
    if (n <= 3) return 1; // For n=1, 2, or 3, the string is "122...", which has exactly one '1'

    // Allocate memory for the string up to length n + 1
    // We store integers 1 and 2 instead of characters '1' and '2' for easier math.
    int* s = (int*)malloc((n + 1) * sizeof(int));
    
    // Initialize the base case for the sequence: "1 2 2"
    s[0] = 1;
    s[1] = 2;
    s[2] = 2;

    int head = 2; // Pointer to read the group length from s
    int tail = 3; // Pointer to append new elements into s
    int numToAppend = 1; // The next character to append flips between 1 and 2

    // Simulate string generation up to length n
    while (tail < n) {
        int count = s[head]; // Read how many times to append numToAppend

        for (int i = 0; i < count && tail < n; i++) {
            s[tail++] = numToAppend;
        }

        // Flip the number to append between 1 and 2
        numToAppend = (numToAppend == 1) ? 2 : 1;
        
        // Move the head pointer forward to get the next group length
        head++;
    }

    // Count the number of 1's in the first n elements
    int onesCount = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 1) {
            onesCount++;
        }
    }

    // Free dynamically allocated memory
    free(s);

    return onesCount;
}

#include <string.h>
#include <stdbool.h>

// Helper function to check if word is a subsequence of s
bool isSubsequence(const char* word, const char* s) {
    int i = 0, j = 0;
    while (word[i] != '\0' && s[j] != '\0') {
        if (word[i] == s[j]) {
            i++;
        }
        j++;
    }
    return word[i] == '\0'; // Returns true if the entire word was found in s
}

char* findLongestWord(char* s, char** dictionary, int dictionarySize) {
    char* bestWord = "";
    int bestLen = 0;

    for (int i = 0; i < dictionarySize; i++) {
        char* word = dictionary[i];
        int len = strlen(word);

        // Optimization: Only check if the word can potentially replace the current bestWord
        if (len > bestLen || (len == bestLen && strcmp(word, bestWord) < 0)) {
            if (isSubsequence(word, s)) {
                bestWord = word;
                bestLen = len;
            }
        }
    }

    return bestWord;
}

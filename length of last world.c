int lengthOfLastWord(char* s) {
    int len = strlen(s);
    int count = 0;
    
    // Step 1: Start at the end of the string
    int i = len - 1;
    
    // Step 2: Skip any trailing spaces at the very end
    while (i >= 0 && s[i] == ' ') {
        i--;
    }
    
    // Step 3: Count the characters of the actual last word
    while (i >= 0 && s[i] != ' ') {
        count++;
        i--;
    }
    
    return count;
}
   
   

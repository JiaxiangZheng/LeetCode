class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        const char* word = NULL; bool word_beg = false;
        while (*s != '\0') {
            if (*s != ' ') {
                if (!word_beg) {
                    word = s; word_beg = true;
                }
            } else {
                word_beg = false;
            }
            ++s;
        }
        if (word == NULL) return 0;
        int len = 0;
        while (*word != ' ' && *word != '\0') len++, ++word;
        return len;
    }
};


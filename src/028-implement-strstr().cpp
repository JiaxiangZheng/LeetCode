/*
    http://leetcode.com/onlinejudge#question_28
    Implement strStr().

    Returns a pointer to the first occurrence of needle in haystack, or null if
    needle is not part of haystack
*/

class Solution {
public:
    char *strStr(const char *haystack, char *needle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (needle == NULL)
            return haystack;
        int len_hay = strlen(haystack), len_needle = strlen(needle);
        if (len_hay < len_needle) return NULL;
        int cmp_count = len_hay - len_needle;
        for (int i=0; i<=cmp_count; ++i) {
            int k = 0;
            while (k < len_needle && haystack[i+k] == needle[k]) k++;
            if (k == len_needle) return haystack+i;
        }
        return NULL;
    }
};


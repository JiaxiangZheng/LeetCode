/*
    http://leetcode.com/onlinejudge#question_10 

    Implement regular expression matching with support for '.' and '*'.

    Some examples:
    isMatch("aa","a") ? false
    isMatch("aa","aa") ? true
    isMatch("aaa","aa") ? false
    isMatch("aa", "a*") ? true
    isMatch("aa", ".*") ? true
    isMatch("ab", ".*") ? true
    isMatch("aab", "c*a*b") ? true
 */
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        if (*p == '\0')  return *s == *p;      
        if (*(p+1) != '*') {
            return ((*p == '.' && *s != '\0') || (*p == *s) && isMatch(s+1, p+1));
        } else {
            while (*p == *s || (*p == '.' && *s != '\0')) {
                if (isMatch(s, p+2)) return true;
                s++;
            }
        }
        return isMatch(s, p+2);
    }
};

/* match: search for regexp anywhere in text */
int match(char *regexp, char *text)
{
    if (regexp[0] == '^')
        return matchhere(regexp+1, text);
    do {    /* must look even if string is empty */
        if (matchhere(regexp, text))
            return 1;
    } while (*text++ != '\0');
    return 0;
}

/* matchhere: search for regexp at beginning of text */
int matchhere(char *regexp, char *text)
{
    if (regexp[0] == '\0')
        return 1;
    if (regexp[1] == '*')
        return matchstar(regexp[0], regexp+2, text);
    if (regexp[0] == '$' && regexp[1] == '\0')
        return *text == '\0';
    if (*text!='\0' && (regexp[0]=='.' || regexp[0]==*text))
        return matchhere(regexp+1, text+1);
    return 0;
}

/* matchstar: search for c*regexp at beginning of text */
int matchstar(int c, char *regexp, char *text)
{
    do {    /* a * matches zero or more instances */
        if (matchhere(regexp, text))
            return 1;
    } while (*text != '\0' && (*text++ == c || c == '.'));
    return 0;
}


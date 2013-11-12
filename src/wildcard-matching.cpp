#include <cstdio>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (*p == 0) {     // 应该完成匹配
            return *s == 0;
        } else if (*s == 0) {
            return false;
        } else if (*p == '?') { // 匹配任一字符
            return isMatch(s+1, p+1);
        } else if (*p == '*') {
            const char* ps = s;
            while (*ps != 0) {
                if (isMatch(ps, p+1)) return true;
                ++ps;
            }
            return isMatch(ps, p+1);
        } else if (*p != *s) return false;
        return isMatch(s+1, p+1);
    }
};

int main() {
    Solution s;
    cout << s.isMatch("aa","a") << endl;             //  → false
    cout << s.isMatch("aa","aa") << endl;        // → true
    cout << s.isMatch("aaa","aa") << endl;        // → false
    cout << s.isMatch("aa", "*") << endl;        // → true
    cout << s.isMatch("aa", "a*") << endl;        // → true
    cout << s.isMatch("ab", "?*") << endl;        // → true
    cout << s.isMatch("aab", "c*a*b") << endl;        // → false
    
    return 0;
}

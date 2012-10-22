#include <sstream>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string str(s);
        stringstream ss(str);
        string word, pre_word;
        while (ss >> word)
        {
            pre_word = word;
        }
        return pre_word.length();
        
    }
};
class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        const char* p = s;
        int cnt = 0, pre_cnt = 0;
        while (1)
        {
            cnt = 0;
            while (*p != '\0' && *(p++) != ' ') ++cnt;
            if (cnt != 0) pre_cnt = cnt;
            if (*p == '\0') break;
        }
        return pre_cnt;
    }
};


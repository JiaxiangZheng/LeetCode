// using DP : L[i] = max{L[i-1], sub_str.length()+1}, sub_str is the maximum
// substring of S[k, i] that contains different characters 
#if 0
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (s.empty()) return 0;
        std::vector<int> len_longest_substr(s.length(), 0);
        len_longest_substr[0] = 1;
        std::string sub_str(1, s[0]);       //Don't forget to push s[0] to sub_str
        for (int i=1; i<s.length(); ++i) {
            string::size_type pos = sub_str.find(s[i]);
            if (pos == string::npos) {
                sub_str.push_back(s[i]);
            } else {
                sub_str = sub_str.substr(pos+1, sub_str.length()-1-pos);
                sub_str.push_back(s[i]);
            }

            len_longest_substr[i] = std::max(len_longest_substr[i-1], (int)sub_str.length());
        }
        return len_longest_substr[s.length() - 1];
    }
};
#endif
#include <utility>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        const int CHAR_SET_SIZE = 256;
        int hash[CHAR_SET_SIZE];
        for (int i=0; i<CHAR_SET_SIZE; ++i) {
            hash[i] = -1;
        }
        int maxlen = 0, beg = 0;
        for (int i=0; i<s.size(); ++i) {
            if (hash[s[i]] != -1 && hash[s[i]] >= beg) {
                beg = hash[s[i]] + 1;
            }
            hash[s[i]] = i;
            maxlen = std::max(maxlen, i - beg + 1);
            printf("%d\t%d\t%d\n", i, beg, maxlen);
        }
        return maxlen;
    }
};

int main() {
    Solution s;
    string str;
    while (cin >> str) {
        cout << s.lengthOfLongestSubstring(str) << endl;
    }
    return 0;
}

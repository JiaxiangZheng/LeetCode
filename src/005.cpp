class Solution {
public:
    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = s.length() << 1;
        int len_max = -1; int center_index = -1;
        --n;
        for (int in=0; in<n; ++in) {
            int len = 0, index = in >> 1;
            if ((in & 1) == 0) { // element of s as center
                len += 1;
                for (int j=1; ; ++j) {
                    if (index - j < 0 || index + j >= s.length()) break;
                    if (s[index+j] != s[index-j]) break;
                    len += 2;
                }
                if (len > len_max)  {
                    len_max = len;
                    center_index = index;
                }
            } else { // empty char as center
                int i = index, j = index + 1;
                while (i >= 0 && j < s.size()) {
                    if (s[i] != s[j]) break;
                    --i; ++j;
                    len += 2;
                }
            }
            if (len > len_max)  {
                len_max = len;
                center_index = index;
            }
        }
        if (len_max % 2 == 1)
            return s.substr(center_index-(len_max/2), len_max);
        else return s.substr(center_index-(len_max/2)+1, len_max);
    }
};


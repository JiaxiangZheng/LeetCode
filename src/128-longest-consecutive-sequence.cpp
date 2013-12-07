class Solution {
public:
    int longestConsecutive_using_map(vector<int>& num) 
    {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (num.empty()) return 0;
        std::set<int> S;
        for (size_t i=0; i<num.size(); ++i) {
            S.insert(num[i]);
        }
        
        int max_len = 0, cur_len = 1;
        for (int i=0; i<num.size(); ++i) {
            if (S.find(num[i]) == S.end()) {
                max_len = std::max(cur_len, max_len);
            } else {
                S.erase(num[i]);
                int val1 = num[i]-1, val2 = num[i]+1;
                while (S.find(val1) != S.end()) {
                    cur_len++;
                    S.erase(val1);
                    val1--;
                }
                while (S.find(val2) != S.end()) {
                    cur_len++;
                    S.erase(val2);
                    val2++;
                }
            }
        }
        max_len = std::max(cur_len, max_len);
        return max_len;
    }
};
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(num.begin(), num.end());
        std::unique(num.begin(), num.end());
        int maxLen = 0;
        int i = 0;
        while (i < num.size()) {
            int cur = num[i];
            int len = 0;
            while (i < num.size() && num[i] == cur + len) {
                ++i;
                ++len;
            }
            if (len > maxLen) maxLen = len;
        }
        return maxLen;
    }
};


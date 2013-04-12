/*
Given an unsorted array of integers, find the length of the longest consecutive
elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
*/

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
    
    int longestConsecutive_using_sort(vector<int> &num) 
    {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (num.empty()) return 0;
        std::sort(num.begin(), num.end());
        std::unique(num.begin(), num.end());
        int max_len = 0, cur_len = 1;
        int pre_number = num[0];
        for (size_t i=1; i<num.size(); ++i) {
            if (num[i] == pre_number+1) cur_len++;
            else {
                max_len = std::max(max_len, cur_len);
                cur_len = 1;
            }
            pre_number = num[i];
        }
        max_len = std::max(max_len, cur_len);
        return max_len;
    }
};


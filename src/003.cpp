/*  
    http://leetcode.com/onlinejudge#question_003

    Given a string, find the length of the longest substring without repeating
    characters. For example, the longest substring without repeating letters for
    "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is
    "b", with the length of 1.
*/
// using DP : L[i] = max{L[i-1], sub_str.length()+1}, sub_str is the maximum
// substring of S[k, i] that contains different characters 
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


/*
    http://leetcode.com/onlinejudge#question_132

    Given a string s, partition s such that every substring of the partition is a
    palindrome.

    Return the minimum cuts needed for a palindrome partitioning of s.

    For example, given s = "aab", Return 1 since the palindrome partitioning
    ["aa","b"] could be produced using 1 cut.
 */ 

class Solution {
public:
    int minCut(const string& str) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        std::vector< std::vector<bool> > flags(str.length(), 
                        std::vector<bool>(str.length(), false));
        for (int i=0; i<str.length(); ++i) {
            flags[i][i] = true;
        }

        for (int i=0; i<str.length()-1; ++i) {
            for (int j=i+1; j<str.length(); ++j) {
                if (j == i+1) {
                    flags[i][j] = (str[i] == str[j]);
                    continue;
                }
                flags[i][j] = flags[i+1][j-1] && (str[i] == str[j]);
            }
        }

        std::vector<int> min_cut(str.length(), INT_MAX);
        min_cut[0] = 0; 
        for (int i=1; i<str.length(); ++i) {
            if (flags[0][i]) {
                min_cut[i] = 0; continue;
            }
            // make sure there is a cut between 0 and i
            for (int j=i-1; j>=0; --j) {
                if (flags[j+1][i]) {
                    min_cut[i] = std::min(min_cut[i], min_cut[j]+1);
                }
            }
        }
        return min_cut[str.length()-1];
    }
};


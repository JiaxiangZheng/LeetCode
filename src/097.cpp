class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        if (s1.size() + s2.size() != s3.size()) return false;
        std::vector< std::vector<bool> > dp(s1.size() +1, std::vector<bool>(s2.size()+1, false));
        dp[0][0] = true;
        for (int i=1; i<= s2.size(); ++i) {
            if (s2[i-1] == s3[i-1]) dp[0][i] = true;
            else break;
        }
        for (int i=1; i<= s1.size(); ++i) {
            if (s1[i-1] == s3[i-1]) dp[i][0] = true;
            else break;
        }
        for (int i=1; i<=s1.size(); ++i) {
            for (int j=1; j<=s2.size(); ++j) {
                dp[i][j] = (s1[i-1] == s3[i+j-1] && dp[i-1][j]) || (s2[j-1] == s3[i+j-1] && dp[i][j-1]);
            }
        }
        return dp[s1.size()][s2.size()];
    }
};


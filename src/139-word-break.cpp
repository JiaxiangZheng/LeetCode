class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<bool> dp(s.length()+1, false);
        int size = s.length();
        if (size == 0) return true;
        for (int i=1; i<=size; ++i) {
            if (!dp[i] && dict.find(s.substr(0, i)) != dict.end()) dp[i] = true;
            if (dp[i]) {
                if (i == size) return true;
                for (int j=i+1; j<=size; ++j) {
                    if (!dp[j] && dict.find(s.substr(i, j-i)) != dict.end()) dp[j] = true;
                    if (j == size && dp[j] == true) return true;
                }
            }
        }
        return false;
    }
};


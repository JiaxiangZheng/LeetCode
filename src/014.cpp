class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (strs.empty()) return string();
        else if (strs.size() == 1) return strs[0];
        string res;
        for (int i=0; i<strs[0].size(); ++i) {
            char ch = strs[0][i];
            bool flag = true;
            for (int j=1; j<strs.size(); ++j) {
                if (i >= strs[j].size()) return res;
                if (strs[j][i] != ch) {
                    flag = false;
                    break;                
                }
            }
            if (flag == false) return res;
            res.push_back(ch);
        }
        return res;
    }
};

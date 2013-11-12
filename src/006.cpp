class Solution {
public:
    string convert(string s, int nRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        if (nRows == 1) return s;
        std::vector<string> strs(nRows);
        int curRow = 0; bool dirDown = true;
        for (int i=0; i<s.length(); ++i) {
            if (dirDown && curRow < nRows-1) {
                strs[curRow].push_back(s[i]);
                curRow++;
            } else if (dirDown && curRow == nRows-1) {
                strs[curRow].push_back(s[i]);
                dirDown = false;
                curRow = nRows-2;
            } else if (!dirDown && curRow > 0) {
                strs[curRow].push_back(s[i]);
                curRow--;
            } else if (!dirDown && curRow == 0) {
                strs[curRow].push_back(s[i]);
                dirDown = true;
                curRow = 1;
            }
        }
        std::string out;
        for (int i=0; i<strs.size(); ++i) {
            out += strs[i];
        }
        return out;
    }
};


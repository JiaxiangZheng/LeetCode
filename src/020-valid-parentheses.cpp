class Solution {
public:
    inline bool leftOpt(char ch) {
        if (ch == '(' || ch == '[' || ch == '{') return true;
        else return false;
    }
    inline bool rightOpt(char ch) {
        if (ch == ')' || ch == ']' || ch == '}') return true;
        else return false;
    }
    bool isValid(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (s.empty()) return true;
        std::stack<char> S;
        if (leftOpt(s[0])) S.push(s[0]);
        else return false;
        for (int i=1; i<s.length(); ++i) {
            if (leftOpt(s[i])) S.push(s[i]);
            else if (rightOpt(s[i])) {
                if (S.empty()) return false;
                char ch = S.top(); S.pop();
                if (s[i] == ')' && ch != '(') return false;
                if (s[i] == ']' && ch != '[') return false;
                if (s[i] == '}' && ch != '{') return false;
            } else return false;
        }
        if (!S.empty()) return false;
        return true;
    }
};


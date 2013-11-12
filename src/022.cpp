class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int left = n, right = n;
        string out;
        std::vector<string> res;
        genPar(left, right, out, res);
        return res;
    }
    void genPar(int left, int right, string& out, std::vector<string>& res) {
        if (left > right || left < 0) return;
        if (left == 0 && right == 0) {
            res.push_back(out);
            return;        
        }
        out.push_back('(');
        genPar(left-1, right, out, res);
        out.pop_back();
        out.push_back(')');
        genPar(left, right-1, out, res);
        out.pop_back();
    }
};


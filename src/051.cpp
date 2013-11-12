#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        std::vector<int> col(n);
        std::vector<bool> visit(n, false);
        outputs.clear();
        for (int i=0; i<n; ++i) {
            col[0] = i; visit[col[0]] = true;
            solve(col, visit, 1);
            visit[i] = false;
        }
        return outputs;
    }
    
    void solve(std::vector<int>& col, std::vector<bool>& visit, int row) {
        if (row == col.size()) {    // output the result
            std::vector<string> output(col.size(), string(col.size(), '.'));
            for (int i=0; i<col.size(); ++i) {
                output[i][col[i]] = 'Q';
            }
            outputs.push_back(output);
            return;
        }
        for (int i=0; i<col.size(); ++i) { 
            if (!visit[i] && judgeDiagal(col, visit, row, i)) {     // if current col is not visit, check the diagnal, if it's OK, then go deeper
                col[row] = i; visit[i] = true;
                solve(col, visit, row+1);
                visit[i] = false;
            }
        }
        return;
    }
    bool judgeDiagal(std::vector<int>& col, std::vector<bool>& visit, int row, int i) {     // check if the (row, i) can be valid, if OK, return true. % [will make col[row] = i]
        bool flag = true; int n = col.size();
        for (int j=1; flag && j <= row;++j) {
            if (i-j >= 0 && col[row-j] == i-j) flag = false;
            if (i+j < n && col[row-j] == j+i) flag = false;
        }
        return flag;
    }
    
private:
    std::vector<std::vector<string> > outputs;    
};


int main() {
    Solution s;
    int n = 8;
    cin >> n;
    auto result = s.solveNQueens(n);
    for (int i=0; i<result.size(); ++i) {
        for (int j=0; j<n; ++j) {
            cout << result[i][j] << endl;
        }
        cout << endl;
    }
    return 0;
}

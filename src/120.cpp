#include <iostream>
#include <vector>
using namespace std;

const int MAX = INT_MAX;
class Solution {        // My solution
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (triangle.empty()) return 0;
        std::vector<int> dp(triangle.size(), MAX);
        dp[0] = triangle[0][0];
        int rows = triangle.size();
        for (int i=1; i<rows; ++i) {
            int elem_n = i+1;
            int prev = MAX;     // 会被覆盖，需要备份前一个
            for (int j=0; j<elem_n; ++j) {
                int min_elem = dp[j];
                min_elem = std::min(min_elem, prev);
                prev = dp[j];
                dp[j] = min_elem + triangle[i][j];
            }
        }
        int res = dp[0];
        for (int i=1; i<dp.size(); ++i) {
            res = std::min(res, dp[i]);
        }
        return res;
    }
};

class Solution {
public:
    int minimumTotal(vector<vector<int> > &t) {
        int n = t.size();
        vector<int> p (n+1, 0);
        while(n-- > 0)
            for(int i = 0; i <= n; ++i) 
                p[i] = t[n][i] + ((p[i] < p[i+1])? p[i] : p[i+1]);
        return p[0];
    }
};
int main() {
    vector<vector<int> > triangle;
    triangle.push_back(vector<int>(1, -1));
    std::vector<int> t; t.push_back(3); t.push_back(2); 
    triangle.push_back(t);
    t.clear(); t.push_back(-3);t.push_back(1);t.push_back(-1);
    triangle.push_back(t);
    Solution s;
    cout << s.minimumTotal(triangle) << endl;
    return 0;
}

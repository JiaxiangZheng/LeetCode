class Solution {
public:
    int uniquePaths(int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        std::vector<std::vector<int> > Paths(m, std::vector<int>(n, 1));
        for (int i=1; i<m; ++i) {
            for (int j=1; j<n; ++j) {
                Paths[i][j] = Paths[i-1][j] + Paths[i][j-1];
            }
        }
        return Paths[m-1][n-1];
    }
};


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (obstacleGrid.empty()) return 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        std::vector<std::vector<int> > paths(m, std::vector<int>(n, 0));
        if (obstacleGrid[0][0] == 1) return 0;
        paths[0][0] = 1;
        for (int i=1; i<m; ++i) {
            if (obstacleGrid[i][0] == 1)
                paths[i][0] = 0;
            else paths[i][0] = std::min(paths[i-1][0], 1);
        }
        for (int i=1; i<n; ++i) {
            if (obstacleGrid[0][i] == 1)
                paths[0][i] = 0;
            else paths[0][i] = std::min(paths[0][i-1], 1);
        }

        for (int i=1; i<m; ++i) {
            for (int j=1; j<n; ++j) {
                if (obstacleGrid[i][j] == 1)
                    paths[i][j] = 0;
                else paths[i][j] = paths[i-1][j] + paths[i][j-1];
            }
        }
        return paths[m-1][n-1];
    }
};


class Solution {        // 不会超时，但好像有bug
public:
    bool bfs(vector<vector<char> > &grid, int row, int col, string pattern) {
        int rows = grid.size(), cols = grid[0].size();
        std::vector<std::vector<bool> > visit(rows, std::vector<bool>(cols, false));
        std::vector<std::vector<int> > paths(rows, std::vector<int>(cols, -1));
        std::queue<int> Q;
        Q.push(row*cols + col); visit[row][col] = true; paths[row][col] = 0;
        while (!Q.empty()) {
            int front = Q.front(); Q.pop(); int i = front / cols, j = front % cols;
            if (paths[i][j] + 1 == pattern.size()) return true;
            if (i > 0 && pattern[paths[i][j]+1] == grid[i-1][j] && !visit[i-1][j]) {      // 向上
                visit[i-1][j] = true; paths[i-1][j] = paths[i][j] + 1;
                Q.push((i-1)*cols+j);
            }
            if (i < rows-1 && pattern[paths[i][j]+1] == grid[i+1][j] && !visit[i+1][j]) { // 向下
                visit[i+1][j] = true; paths[i+1][j] = paths[i][j] + 1;
                Q.push((i+1)*cols+j);
            }
    
            if (j > 0 && pattern[paths[i][j]+1] == grid[i][j-1] && !visit[i][j-1]) {  // 向左
                visit[i][j-1] = true; paths[i][j-1] = paths[i][j] + 1;
                Q.push(i*cols+j-1);
            }
            if (j < cols-1 && pattern[paths[i][j]+1] == grid[i][j+1] && !visit[i][j+1]) { // 向右
                visit[i][j+1] = true; paths[i][j+1] = paths[i][j] + 1;
                Q.push(i*cols+j+1);
            }
        }
        return false;
    }
    bool exist(vector<vector<char> > &grid, string pattern) {
        if (grid.empty()) return false;
        int rows = grid.size(), cols = grid[0].size();
        if (rows * cols < pattern.size()) return false;
        for (int i=0; i<rows; ++i) {
            for (int j=0; j<cols; ++j) {
                if (grid[i][j] == pattern[0]) {
                    bool flag = bfs(grid, i, j, pattern);
                    if (flag) return true;
                }
            }
        }       
        return false;
    }

};

class Solution {    // dfs有可能会超时
public:
    bool dfs(std::vector<std::vector<char> >& grid, int row, int col, string pattern, int i) {
        if (row < 0 || row >= grid.size()) return false;
        if (col < 0 || col >= grid[0].size()) return false;
        if (grid[row][col] != pattern[i]) return false;
        if (i+1 == pattern.size()) return true;
        char ch = grid[row][col];
        grid[row][col] = '#';
        bool flag = dfs(grid, row+1, col, pattern, i+1);
        flag = flag || dfs(grid, row-1, col, pattern, i+1);
        flag = flag || dfs(grid, row, col-1, pattern, i+1);
        flag = flag || dfs(grid, row, col+1, pattern, i+1);
        grid[row][col] = ch;
        return flag;
    }
    bool exist(vector<vector<char> > &grid, string pattern) {
        if (grid.empty()) return false;
        int rows = grid.size(), cols = grid[0].size();
        if (rows * cols < pattern.size()) return false;
        for (int i=0; i<rows; ++i) {
            for (int j=0; j<cols; ++j) {
                if (grid[i][j] == pattern[0]) {
                    bool flag = dfs(grid, i, j, pattern, 0);
                    if (flag) return true;
                }
            }
        }       
        return false;
    }

};



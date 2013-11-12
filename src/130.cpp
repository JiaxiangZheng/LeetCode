class Solution {
public:
    void dfs(vector<vector<char>> &board, int i, int j) {
        board[i][j] = 'O';
        if (i-1 >= 0 && board[i-1][j] == 'C') {
            dfs(board, i-1, j);
        }
        if (i+1 < board.size() && board[i+1][j] == 'C') {
            dfs(board, i+1, j);
        }
        if (j-1 >= 0 && board[i][j-1] == 'C') {
            dfs(board, i, j-1);
        }
        if (j+1 < board[0].size() && board[i][j+1] == 'C') {
            dfs(board, i, j+1);
        }
        return;
    }
    void solve(vector<vector<char>> &board) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (board.empty()) return;
        int rows = board.size(), cols = board[0].size();
        for (int i=1; i<rows-1; ++i) {
            for (int j=1; j<cols-1; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'C';
                }
            }
        }
        for (int i=0; i<rows; ++i) {
            if (board[i][0] == 'O') dfs(board, i, 0);
            if (board[i][cols-1] == 'O') dfs(board, i, cols-1);
        }
        for (int i=1; i<cols-1; ++i) {
            if (board[0][i] == 'O') dfs(board, 0, i);
            if (board[rows-1][i] == 'O') dfs(board, rows-1, i);
        }
        for (int i=0; i<rows; ++i) {
            for (int j=0; j<cols; ++j) {
                if (board[i][j] == 'C') board[i][j] = 'X';
            }
        }
        return;
    }
};


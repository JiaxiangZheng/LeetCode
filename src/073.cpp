class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (matrix.empty()) return;
        int rows = matrix.size(), cols = matrix[0].size();
        
        int row = -1, col = -1;
        for (int i=0; i<rows * cols; ++i) {
            if (matrix[i/cols][i%cols] == 0) {
                row = i / cols;
                col = i % cols;
                break;
            }
        }
        if (row == -1 && col == -1) return;    // no zero element

        for (int i=0; i<rows; ++i) {
            for (int j=0; j<cols; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][col] = 0;
                    matrix[row][j] = 0;
                }
            }
        }
        
        for (int i=0; i<rows; ++i) {
            if (row != i && matrix[i][col] == 0) {
                for (int j=0; j<cols; ++j) matrix[i][j] = 0;
            }
        }
        
        for (int j=0; j<cols; ++j) {
            if (matrix[row][j] == 0) {
                for (int i=0; i<rows; ++i) matrix[i][j] = 0;
            }
        }
        
        for (int j=0; j<cols; ++j) matrix[row][j] = 0;
        return;
    }
};


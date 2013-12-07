#include <iostream>
#include <vector>
#include <utility>
using namespace std;


class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = matrix.size();
        int rows = n / 2;
        for (int i = 0; i<rows; ++i) {
            for (int j=i; j<n-i-1; ++j) {
                int t = matrix[i][j];
                matrix[i][j] = matrix[n-1-j][i];
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
                matrix[j][n-1-i] = t;
            }
        }
    }
};

int main() {
    int n = 9;
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            matrix[i][j] = i*n + j + 1;
        }
    }
    Solution s;
    int cnt = 4;
    while (cnt--) {
        s.rotate(matrix);
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                printf("%8d", matrix[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> out;
        if (matrix.empty()) return out;
        int L = 0, R = matrix[0].size() - 1, U = 0, D = matrix.size() - 1;
        while (L <= R && U <= D) {
            if (L == R && U == D) {     // 1 element only
                out.push_back(matrix[L][U]);
            } else if (L == R) {        // 1 column
                for (int i=U; i<=D; ++i) out.push_back(matrix[i][L]);
            } else if (U == D) {        // 1 row
                for (int i=L; i<=R; ++i) out.push_back(matrix[U][i]);
            } else {                    // m * n matrix
                for (int i=L; i<R; ++i) {
                    out.push_back(matrix[U][i]);
                }
                for (int i=U; i<D; ++i) {
                    out.push_back(matrix[i][R]);
                }
                for (int i=R; i>L; --i) {
                    out.push_back(matrix[D][i]);
                }
                for (int i=D; i>U; --i) {
                    out.push_back(matrix[i][L]);
                }
            }
            --R; --D; ++L; ++U;
        }
        return out;
    }
};


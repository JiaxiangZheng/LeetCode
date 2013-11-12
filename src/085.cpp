//Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle
//containing all ones and return its area.
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (matrix.empty()) {
            return 0;
        }

        int rows = matrix.size(), cols = matrix[0].size();
        vector<int> H(cols), L(cols), R(cols, cols);

        int ret = 0;
        for (int i = 0; i < rows; ++i) {
            int left = 0, right = cols;
            // calculate L(i, j) from left to right
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] == '1') {
                    ++H[j];
                    L[j] = max(L[j], left);
                }
                else {
                    left = j+1;
                    H[j] = 0; L[j] = 0; R[j] = cols;
                }
            }
            // calculate R(i, j) from right to right
            for (int j = cols-1; j >= 0; --j) {
                if (matrix[i][j] == '1') {
                    R[j] = min(R[j], right);
                    ret = max(ret, H[j]*(R[j]-L[j]));
                }
                else {
                    right = j;
                }
            }
        }

        return ret;
    }
};


int main() {
    string str;
    cin >> str;
    std::vector<int> bins(str.length(), 0);
    bins[0] = str[0] == '0' ? 0 : 1;
    for (int i=1; i<str.length(); ++i) {
        if (str[i] == '0')
            bins[i] = 0;
        else bins[i] = bins[i-1] + 1;
    }

    int max = 0;
    for (int i=0; i<bins.size(); ++i) {
        printf("%d ", bins[i]);
        if (max < bins[i]) max = bins[i];
    }
    printf("\cols");
    cout << max << endl;
    return 0;
}

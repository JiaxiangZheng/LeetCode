class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        std::vector<std::vector<int> > res(n, std::vector<int>(n));
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        int sx = 0, sy = -1, dim = 0, len = n;
        int N = n * n;
        int i = 0;
        while (i < N) {
            for (int j=0; j<len; ++j) {
                sx += dx[dim]; sy += dy[dim];
                res[sx][sy] = ++i;
            }
            dim = (dim + 1) % 4;
            if ((dim&1)==1) len--;
        }
        return res;
    }
};


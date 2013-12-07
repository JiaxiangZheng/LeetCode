class Solution {
public:
    int numTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int cnt = 0;
        std::vector<int> f(n+1);
        f[0] = 1; f[1] = 1;  f[2] = 2;
        for (int i=3; i<=n; ++i) {
            f[i] = 0;
            for (int j=0; j<i; ++j)
                f[i] += f[j]*f[i-1-j];
        }
        return f[n];
    }
};


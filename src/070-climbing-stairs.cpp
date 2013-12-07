class Solution {
public:
    int climbStairs(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n == 1) return 1;
        int f[3] = {1, 1, 2};
        for (int i=2; i<=n; ++i) {
            f[2] = f[0] + f[1];
            f[0] = f[1];
            f[1] = f[2];
        }
        return f[2];
    }
};


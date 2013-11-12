class Solution {
public:
    double pow(double x, long long n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n == 0) return 1.0;
        else if (n < 0) return 1.0 / pow(x, -n);
        else {
            double res = 1.0;
            while (n > 0) {
                if ((n&1)==1) res *= x;
                x *= x;
                n >>= 1;
            }
            return res;
        }
    }
};


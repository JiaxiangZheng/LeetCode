class Solution {
public:
    string getPermutation(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        assert (k >= 1);
        int total = 1;
        for (int i=2; i<=n; ++i) total *= i;
        k = k % total;  if (k == 0) k = total;
        string dig = "0123456789";
        string str; 
        for (int i=1; i<=n; ++i) str.push_back(dig[i]);
        if (k < total - k + 1) {
            for (int i=2; i<=k; ++i) {
                next_permutation(str.begin(), str.end());
            }
        } else {
            k = total + 1 - k;
            for (int i=1; i<=k; ++i) {
                prev_permutation(str.begin(), str.end());
            }
        }
        return str;
    }
};

class Solution {
public:
    string getPermutation(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string res;
        int factorial = 1;
        for (int i=1; i<=n; ++i) {
            res.push_back('0' + i);
            factorial *= i;
        }
        
        k--;
        k %= factorial;
        
        for (int i=0; i<n; ++i) {
            factorial /= (n-i);
            int index = k / factorial;
            k %= factorial;
            
            char temp = res[index];
            for (int j=index+1; j<n-i; ++j) {
                res[j-1] = res[j];
            }
            res[n-i-1] = temp;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};



class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n == 0 || A == NULL) return 0; 
        int len = 1;
        for (int i=1; i<n; ++i) {
            if (A[i] != A[len-1]) {
                A[len++] = A[i];
            }
        }
        return len;
    }
};


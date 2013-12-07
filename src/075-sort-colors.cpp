class Solution {
public:
    void sortColors(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int r = 0, b = 0;
        for (int i=0; i<n; ++i) {
            if (A[i] == 0) {
                ++r;
            } else if (A[i] == 2) {
                ++b;
            }
        }
        int w = n - r - b;
        for (int i=0; i<r; ++i) {
            A[i] = 0;
        }
        for (int i=0; i<w; ++i) {
            A[r+i] = 1;
        }
        for (int i=0; i<b; ++i) {
            A[r+w+i] = 2;
        }
        return;
    }
};
class Solution {
public:
    void sortColors(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int rw = 0, b = n - 1;
        for (int i=0; i<=b; ++i) {
            if (A[i] == 0) {
                swap(A[rw++], A[i]);
            } else if (A[i] == 2) {
                swap(A[b--], A[i]);
                --i;
            } else continue;
        }
        return;
    }
};

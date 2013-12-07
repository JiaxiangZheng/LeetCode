// merge sorted arrays
// easy to implement
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i = m-1, j = n-1;
        int tail = m + n - 1;
        while (i >= 0 && j >= 0) {
            if (A[i] >= B[j]) {
                A[tail] = A[i];
                --i;
            } else {
                A[tail] = B[j];
                --j;
            }
            --tail;
        }
        while (j >= 0) {
            A[tail--] = B[j--];
        }
        return;
    }
};


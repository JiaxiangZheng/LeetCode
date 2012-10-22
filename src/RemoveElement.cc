class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int newLength = 0;
        int *B = new int[n];
        for (int i=0; i<n; ++i)
            if (A[i] != elem)
                B[newLength++] = A[i];
        for (int i=0; i<newLength; ++i)
            A[i] = B[i];
        delete[] B;
        return newLength;
    }
};






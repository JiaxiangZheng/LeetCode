class Solution {
public:
    int maxSubArray(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int S = INT_MIN, SA = INT_MIN;
        for (int i=0; i<n; ++i) {
            SA = std::max(SA + A[i], A[i]);
            if (SA > S) S = SA;
        }
        return S;
    }
};


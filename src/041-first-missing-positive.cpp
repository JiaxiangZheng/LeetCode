class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n == 0) return 1;
        std::set<int> S;
        for (int i=0; i<n; ++i) {
            if (A[i] > 0) S.insert(A[i]);
        }
        for (int k=1; k<=n; ++k) {
            if (S.find(k) == S.end()) return k;
        }
        return n+1;
    }
};
class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        std::vector<bool> bitmap(n+1, false);
        for (int i=0; i<n; ++i) {
            if (A[i] <= 0 || A[i] > n) continue;
            bitmap[A[i]] = true;
        }
        for (int i=1; i<=n; ++i) {
            if (!bitmap[i]) return i;
        }
        return n+1;
    }
};
class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        for (int i=n-1; i>=0; --i) {
            while (A[i] > 0 && A[i] < n && A[i] != i && A[i] != A[A[i]]) {
                swap(A[i], A[A[i]]);
            }
        }
        for (int i=1; i<n; ++i) {
            if (A[i] != i) return i;
        }
        if (A[0] == n) return n+1;
        return n;
    }
};


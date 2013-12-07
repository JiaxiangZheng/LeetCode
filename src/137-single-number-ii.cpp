class Solution {
public:
    int singleNumber(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        std::map<int, int> m;
        for (int i=0; i<n; ++i) m[A[i]]++;
        for (auto it=m.begin(); it != m.end(); ++it) if (it->second == 1) return it->first;
        return -1;
    }
};


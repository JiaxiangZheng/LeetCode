class Solution {
public:
    int canCompleteCircuit(vector<int> &a, vector<int> &g) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int len = a.size();
        if (a.empty()) return -1;
        if (len == 1) {
            return a[0] >= g[0] ? 0 : -1;
        }
        int gas = a[0] - g[0];
        int start = 0, end = 1;
        while (start != end) {
            if (gas >= 0) {
                gas += a[end] - g[end];
                end = (end + 1) % len;
            } else {
                start = (start + len - 1) % len;
                gas += a[start] - g[start];
            }
        }
        if (gas < 0) return -1;
        else return start;
    }
};


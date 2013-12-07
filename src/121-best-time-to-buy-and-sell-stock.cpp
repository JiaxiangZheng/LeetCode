class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (prices.empty() || prices.size() == 1) return 0;
        int max_diff = 0;
        int min_val = prices[0];
        for (int i=1; i<prices.size(); ++i) {
            max_diff = std::max(max_diff, prices[i] - min_val);
            if (prices[i] < min_val) min_val = prices[i];
        }
        return max_diff;
    }
};


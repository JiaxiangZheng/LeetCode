class Solution {
public:
    int candy(vector<int> &ratings) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> candys(ratings.size(), 1);
        for (int i=0; i<ratings.size()-1; ++i) {
            if (ratings[i+1] > ratings[i]) candys[i+1] = max(candys[i] + 1, candys[i+1]);
        }
        for (int i=ratings.size()-2; i>=0; --i) {
            if (ratings[i] > ratings[i+1]) candys[i] = max(candys[i], candys[i+1] + 1);
        }
        int sum = 0;
        for (int i=0; i<candys.size(); ++i) sum += candys[i];
        return sum;
    }
};


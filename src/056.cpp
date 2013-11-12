/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool operator < (const Interval& rhs, const Interval& rrs) {
    return rhs.start < rrs.start;
}
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        std::vector<Interval> resultIntervals;
        if (intervals.empty()) return resultIntervals;
        sort(intervals.begin(), intervals.end());
        resultIntervals.push_back(intervals[0]);
        for (int i=1; i<intervals.size(); ++i) {
            if (resultIntervals.back().end < intervals[i].start) {
                resultIntervals.push_back(intervals[i]);
            } else {
                resultIntervals.back().end = std::max(resultIntervals.back().end, intervals[i].end);
            }
        }
        return resultIntervals;
    }
};


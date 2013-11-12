/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        // insert
        int N = intervals.size(); intervals.resize(N+1); intervals[N] = newInterval;
        int i = N;
        while (i > 0 && intervals[i].start < intervals[i-1].start) {
            swap(intervals[i], intervals[i-1]);
            --i;
        }
        intervals[i] = newInterval;
        
        // merge
        std::vector<Interval> resultIntervals; resultIntervals.push_back(intervals[0]);
        for (int i = 1; i<=N; ++i) {
            if (resultIntervals.back().end >= intervals[i].start) {
                resultIntervals.back().end = std::max(intervals[i].end, resultIntervals.back().end);
            } else {
                resultIntervals.push_back(intervals[i]);
            }
        }
        return resultIntervals;
    }
};


/** Question : 
 * Given a set of non-overlapping intervals, insert a new interval into the
 * intervals (merge if necessary). You may assume the intervals were initially
 * sorted according to their start times.
 * Example 1:
 *  Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9]. 
 * Example 2:
 *  Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as 
 *      [1,2],[3,10],[12,16].
 *  This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
 */
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {    //Accept
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        //Be careful at the boundary
        std::vector<Interval> out;
        bool flag = true;
        for (int i=0; i<intervals.size(); ++i)
        {
            if (intervals[i].start > newInterval.end) {
                if (flag) {out.push_back(newInterval);flag = false;}
                out.push_back(intervals[i]);
            }
            else if (intervals[i].end < newInterval.start) 
                out.push_back(intervals[i]);
            else {
                newInterval.start = std::min(newInterval.start, intervals[i].start);
                newInterval.end  = std::max(newInterval.end, intervals[i].end);
            }
        }
        if (flag) out.push_back(newInterval);
        return out;
    }
};
/**
 * The following version erase the assumption that Intervals are sorted.
 */
bool operator< (const Interval& ref1, const Interval& ref2)
{
    return ref1.start < ref2.start;
}

class SolutionExtention {   //Accept
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    {
        std::vector<Interval> out;
        for (int i=0; i<intervals.size(); ++i)
        {
            if (intervals[i].end < newInterval.start || intervals[i].start > newInterval.end)
                out.push_back(intervals[i]);
            else {
                newInterval.start = std::min(newInterval.start, intervals[i].start);
                newInterval.end  = std::max(newInterval.end, intervals[i].end);
            }
        }
        out.push_back(newInterval);
        std::sort(out.begin(), out.end(), interval_compare);
        return out;
    }
};


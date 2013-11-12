/*
 * Given a sorted array of integers, find the starting and ending position of a
 * given target value.  Your algorithm's runtime complexity must be in the order
 * of O(log n).  If the target is not found in the array, return [-1, -1].  For
 * example, Given [5, 7, 7, 8, 8, 10] and target value 8, return [3, 4].  
 * */

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        std::vector<int> As(A, A+n);
        std::vector<int>::iterator it_l = std::lower_bound(As.begin(), As.end(), target);
        std::vector<int>::iterator it_u = std::upper_bound(As.begin(), As.end(), target);
        std::vector<int> outRange;
        if (it_l == As.end()) 
            outRange.push_back(-1);outRange.push_back(-1);
            return outRange;
        else {
            outRange.push_back(it_l-As.begin());
            outRange.push_back(it_u-As.begin());
            return std::vector<int>(it_l, it_u);
        }
    }
};


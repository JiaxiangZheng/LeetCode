/*
    http://leetcode.com/onlinejudge#question_27

    Remove Element

    Given an array and a value, remove all instances of that value in place and
    return the new length.

    The order of elements can be changed. It doesn't matter what you leave
    beyond the new length.
*/

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int found_cnt = 0;
        for (int i=0; i<n-found_cnt; ++i) {
            if (A[i] == elem) {
                std::swap(A[n-1-found_cnt], A[i]);
                ++found_cnt;
                i--;
            }
        }
        return n - found_cnt;
    }
};

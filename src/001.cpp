/*
    http://leetcode.com/onlinejudge#question_1

    Given an array of integers, find two numbers such that they add up to a specific
    target number.

    The function twoSum should return indices of the two numbers such that they add
    up to the target, where index1 must be less than index2. Please note that your
    returned answers (both index1 and index2) are not zero-based.

    You may assume that each input would have exactly one solution.

    Input: numbers={2, 7, 11, 15}, target=9
    Output: index1=1, index2=2
*/
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> result(2, -1);
        // std::sort(numbers.begin(), numbers.end());
        for (int i=0; i<numbers.size(); ++i) {
            int val = target - numbers[i];
            bool flag = false;
            int j=numbers.size() - 1;
            for (; j >= 0 && !flag; --j) {
                if (i == j) continue;
                if (val == numbers[j]) {flag = true;break;}
            }
            if (flag) {
                result[0] = i+1;
                result[1] = j+1;
            }
        }
        assert (result[0] != -1 && result[1] != -1);
        if (result[0] > result[1]) {
            swap(result[0], result[1]);
        }
        return result;
    }
};


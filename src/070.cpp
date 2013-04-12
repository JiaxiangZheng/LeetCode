/*
    http://leetcode.com/onlinejudge#question_70

    You are climbing a stair case. It takes n steps to reach to the top.  Each
    time you can either climb 1 or 2 steps. In how many distinct ways can you
    climb to the top?
 */

class Solution {
public:
    int climbStairs(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n == 1) return 1;
        else if (n == 2) return 2;
        int C1 = 1, C2 = 2, C3 = C1 + C2;
        n -= 2;
        while (n--) {
            C3 = C1 + C2;
            C1 = C2;
            C2 = C3; 
        }
        return C3;
    }
};


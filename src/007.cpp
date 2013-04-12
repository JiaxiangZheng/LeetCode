/*  
    http://leetcode.com/onlinejudge#question_007
    
    Reverse a number

    注意溢出，如int数为1000000003，那反转后就溢出了 
*/
class Solution {
public:
    int reverse(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int out = 0;
        bool negtive = false;
        if (x == 0) return 0; 
        else if (x < 0) {
            negtive = true;
            x = -x;
        }
        while (x > 0) {     //注意这个循环条件
            out = 10*out + x % 10;
            x /= 10;
        }
        if (negtive) out = -out;
        return out;
    }
};


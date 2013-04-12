/*  
    http://leetcode.com/onlinejudge#question_007
    
    Reverse a number

    ע���������int��Ϊ1000000003���Ƿ�ת�������� 
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
        while (x > 0) {     //ע�����ѭ������
            out = 10*out + x % 10;
            x /= 10;
        }
        if (negtive) out = -out;
        return out;
    }
};


//determin an interger is Palindrome number without using extra space
class Solution {
public:
    bool isPalindrome(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (x == 0) return true;
        if (x < 0) return false;
        int val = x; int sum = 0;
        while (val / 10 > 0)
        {
            sum = 10*sum + val % 10;
            val = val / 10;
        }
        sum = 10*sum + val;
        
        if (sum == x) return true;
        else return false;
    }
};


class Solution {
public:
    bool isPalindrome(int x, int &y) {
      if (x < 0) return false;
      if (x == 0) return true;
      if (isPalindrome(x/10, y) && (x%10 == y%10)) {
        y /= 10;
        return true;
      } else {
        return false;
      }
    }
    bool isPalindrome(int x) {
      return isPalindrome(x, x);
    }
};


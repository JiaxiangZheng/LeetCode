/*
    http://leetcode.com/onlinejudge#question_009
    
    Determine whether an integer is a palindrome. Do this without extra space.

    The solution is refered to here : http://leetcode.com/2012/01/palindrome-number.html
*/

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

int reverse(int num) {
  assert(num >= 0);   // for non-negative integers only.
  int rev = 0;
  while (num != 0) {
    rev = rev * 10 + num % 10;
    num /= 10;
  }
  return rev;
}

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x == 0) return true;
        if (reverse(x) == x) return true;
        else return false;
    }
};

// using loop
class Solution {
public:
    bool isPalindrome(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (x < 0) return false;
        if (x == 0) return true;
        int div = 1;
        while (x / div > 9) {
            div *= 10;
        }
        while (x > 0) {
            int l = x / div;
            int r = x % 10;
            if (l != r) return false;
            x = x - l*div - r;
            x /= 10;
            div /= 100;
        }
        return true;
    }
};


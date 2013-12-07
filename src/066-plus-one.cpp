class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int add = 1, len = digits.size();
        for (int i=len-1; i>=0; --i) {
            digits[i] += add;
            if (digits[i] > 9) {
                digits[i] -= 10; add = 1;
            } else {
                add = 0;
            }
        }
        if (add > 0) {
            digits.insert(digits.begin(), add);
        }
        return digits;
    }
};


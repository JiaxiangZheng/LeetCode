class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ret;
        if(n < k || k < 1) return ret;
        vector<int> numbers(k,1);
        bool forward = true;
        int icur = 0;
        while (icur >= 0) {
            if (forward) {
                if (icur == k - 1) {
                    ret.push_back(numbers);
                    forward = false;
                } else {
                    if (numbers[icur] < n) {
                        numbers[icur+1] = numbers[icur] + 1;
                        ++icur;
                    } else {
                        forward = false;
                    }
                }
            } else {
                if (numbers[icur] < n) {
                    ++numbers[icur];
                    forward = true;
                } else {
                    --icur;
                }
            }
        }
        return ret;
    }
};


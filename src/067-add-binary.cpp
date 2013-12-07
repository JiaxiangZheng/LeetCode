class Solution {
public:
    string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string out;
        int i = a.length() - 1, j = b.length() - 1;
        int add = 0;

        while (i >= 0 || j >= 0) {
            int sum = add;
            if (i >= 0) sum += (a[i] - '0'); --i;
            if (j >= 0) sum += (b[j] - '0'); --j;
            if (sum > 1) {
                out.push_back(sum - 2 + '0');
                add = 1;
            } else {
                out.push_back(sum + '0');
                add = 0;
            }
        }
        
        if (add > 0) {
            out.push_back(add + '0');
        }
        std::reverse(out.begin(), out.end());
        return out;
    }
};


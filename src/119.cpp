class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        std::vector<double> res(rowIndex + 1, 1);       // ·ÀÖ¹Òç³ö
        for (int i=1; i<=rowIndex; ++i) {
            res[i] = res[i-1]*(rowIndex - i + 1) / i;
        }
        std::vector<int> resInt(res.size());
        for (int i=0; i<resInt.size(); ++i) {
            resInt[i] = static_cast<int>(res[i]);
        }
        return resInt;        
    }
};


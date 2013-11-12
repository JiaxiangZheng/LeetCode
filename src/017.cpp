const char Phone[10][10] = {"", " ", "abc", "def", "ghi",
                            "jkl", "mno", "pqrs", "tuv", "wxyz"};
int Len[10] = {0, 1, 3, 3, 3, 3, 3, 4, 3, 4};

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        std::vector<string> res;
        string temp;
        permutation(digits, 0, temp, res);
        return res;
    }

    void permutation(const string& digits, int pos, std::string temp_output, std::vector<string>& output) {
        if (pos == digits.length()) {
            output.push_back(temp_output);
            return;
        }
        int index = digits[pos] - '0'; 
        if (index == 0 || index == 1) return;
        for (int i=0; i<Len[index]; ++i) {
            temp_output.push_back(Phone[index][i]);
            permutation(digits, pos+1, temp_output, output);
            temp_output.pop_back();
        }
        return;
    }
};


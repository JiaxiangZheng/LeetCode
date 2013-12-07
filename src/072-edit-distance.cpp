#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int minDistance(const string& word1, const string& word2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function        
        if (word1.empty()) return word2.size();
        if (word2.empty()) return word1.size();
        std::vector<std::vector<int> > outMin(word1.size(), std::vector<int>(word2.size()));
        int len1 = word1.size(), len2 = word2.size();
        outMin[0][0] = (word1[0] == word2[0]) ? 0 : 1;
        for (int i=1; i<len1; ++i) {
            outMin[i][0] = outMin[i-1][0]+1;
			if (word1[i] == word2[0] && outMin[i-1][0] == i) outMin[i][0] -= 1;
        }
        for (int i=1; i<len2; ++i) {
            outMin[0][i] = outMin[0][i-1]+1;
			if (word2[i] == word1[0] && outMin[0][i-1] == i) outMin[0][i] -= 1;
        }
        for (int i=1; i<len1; ++i) {
            for (int j=1; j<len2; ++j) {
				outMin[i][j] = std::min(std::min(outMin[i-1][j], outMin[i][j-1])+1, word1[i] == word2[j]?outMin[i-1][j-1]:outMin[i-1][j-1]+1);
            }
        }
        return outMin[len1-1][len2-1];
    }
};

class Solution {
public:
    int minDistance(const string& word1, const string& word2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function        
        if (word1.empty()) return word2.size();
        if (word2.empty()) return word1.size();
        std::vector<std::vector<int> > outMin(word1.size() + 1, std::vector<int>(word2.size() + 1, 0));
        int len1 = word1.size(), len2 = word2.size();
        outMin[0][0] = 0;
        for (int i=1; i<=len1; ++i) outMin[i][0] = i;
        for (int i=1; i<=len2; ++i) outMin[0][i] = i;
        for (int i=1; i<=len1; ++i) {
            for (int j=1; j<=len2; ++j) {
                outMin[i][j] = min(min(outMin[i-1][j], outMin[i][j-1]) + 1, outMin[i-1][j-1] + ((word1[i-1] == word2[j-1]) ?  0 : 1));
            }
        }
        return outMin[len1][len2];
    }
};

int main() {
    Solution s;
    cout << s.minDistance("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdef", "bcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefg") << endl;
    return 0;
}

#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n <= 0) return string();
        string s = "1";
        for (int i=2; i<=n; ++i) {
            string out;
            for (int j=0; j<s.length(); ++j) {
                char cur = s[j];
                int count = 1;
                for (int k=j+1; k<s.length() && s[k] == cur; ++k) {
                    ++count; ++j;
                }
                if (count > 9) printf("opps\n");    // 不可能 
                else out += ('0' + count);
                out += cur;
            }
            s = out;
        }
        return s;
    }
};

int main() {
    Solution s;
    cout << s.countAndSay(10) << endl;
    cout << countAndSay(10) << endl;
}

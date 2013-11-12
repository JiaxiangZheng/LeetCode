#include <sstream>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string countAndSay(int val, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        assert (n >= 0);
        std::string str;
        stringstream ss;
        ss << val;
        ss >> str;
            
        for (int i=1; i<n; ++i) {
            stringstream cur_ss;
            int k=0;int pre_val = str[0]-'0', cnt = 0;
            do {
                if (pre_val == (str[k]-'0')) ++cnt;
                else {
                    cur_ss << cnt << pre_val;
                    pre_val = str[k] - '0';
                    cnt = 1;
                }
                k++;
            }while (k < str.size());
            cur_ss << cnt << pre_val;
			string new_str;
            cur_ss >> new_str;
			str = new_str;
        }
        return str;
    }
};

int main(int argc, char** argv) {
	if (argc != 3) return -1;
	int val = atoi(argv[1]);
    int n = atoi(argv[2]); 
    Solution s;
    std::cout << s.countAndSay(val, n) << std::endl;
    return 0;
}



class Solution2 {
public: 
string countAndSay(int n) {

    if (n == 1)
        return "1";

    string str_con;
    string temp_ans = "";
    string ans = "1";

    for (int i=1; i<n; ++i)
    {
        int ctr = 0;
        char temp_char = ans[0];
        int ans_size = ans.size();

        for (int j=0; j<ans_size; ++j)
        {
            if (ans[j] == temp_char)
                ctr++;

            else if (ans[j] != temp_char)
            {
                ostringstream convert;
                convert << ctr;
                str_con = convert.str();
                temp_ans = temp_ans + str_con + temp_char;
                ctr = 1;
                temp_char = ans[j];
            }

            if (j == ans.size()-1)
            {
                    ostringstream convert;
                    convert << ctr;
                    str_con = convert.str();
                    ans = temp_ans + str_con + temp_char;
                    temp_ans = "";
            }
        }
    }

    return ans;
 }
};

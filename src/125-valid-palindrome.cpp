/*
 * =====================================================================================
 *
 *       Filename:  125.cpp
 *
 *    Description:  http://leetcode.com/onlinejudge#question_125
 *
 *        Version:  1.0
 *        Created:  2013/4/7 22:25:08
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jiaxiang Zheng (NULL), jiaxiang.zheng135@gmail.com
 *   Organization:  State Key Lab of CAD&CG
 *
 * =====================================================================================
 */
class Solution {
public:
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string clean_str;
        for (int i=0; i<s.length(); ++i) {
            if (std::isalpha(s[i]))
                clean_str.push_back(std::tolower(s[i]));
            else if (std::isdigit(s[i]))
                clean_str.push_back(s[i]);
        }
        bool flag = true;
        int len = clean_str.length();
        int iter_cnt = len>>1 - 1;
        for (int i=0; i<iter_cnt && flag; ++i) {
            flag = clean_str[i] == clean_str[len-i-1];
        }
        return flag;
    }
};


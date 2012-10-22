#include <iostream>
#include <string>
#include "../include/Vec.h"
using namespace std;

class Solution
{
public:
    int solve(const std::string& str1, const std::string& str2)
    {
        int* arr = new int[str1.length()*str2.length()];
        bool flag = false;
        for (int i=0; i<str2.length(); ++i) {
            if (str1[0] == str2[i])
                flag = true;
            if (flag) arr[i] = 1;
            else arr[i] = 0;
        }
        flag = false;
        for (int i=0; i<str1.length(); ++i) {
            if (str2[0] == str1[i]) flag = true;
            if (flag) arr[str2.length()*i] = 1;
            else arr[str2.length()*i] = 0;
        }
        for (int i=1; i<str1.length(); ++i)
        {
            for (int j=1; j<str2.length(); ++j)
            {
                if (str1[i] == str2[j])
                    arr[i*str2.length()+j] = arr[i*str2.length()+j-1-str2.length()] + 1;
                else {
                    arr[i*str2.length()+j]
                        = std::max(arr[i*str2.length()+j-str2.length()], arr[i*str2.length()+j-1]);
                }
            }
        }
        int _maxlen = arr[str1.length()*str2.length() - 1];
        delete []arr; 
        return _maxlen;
    }
};
/* 
 * author : jiaxiang.zheng135@gmail.com
 */ 
int main()
{
    Solution solver;
    int res = solver.solve("thas", "that");
    return 0;
}

#include <cstdio>
#include <iostream>
using namespace std;

class Solution {
public:
    int atoi(const char *str) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        assert (str != NULL);
        if (*str == '\0') return 0;
        while (*str == ' ') ++str;
        const char* p = str;
        bool neg = false; 
        if (*p == '-') {neg = true; ++p;}
        else if (*p == '+') ++p;

        int res = 0;
        while (isdigit(*p)) {
            if ((res == 214748364 && *p > '7') || (res > 214748364)) {
                return neg ? INT_MIN : INT_MAX;
            }
            res = 10 * res + *p - '0';
            ++p;
        }
        return neg ? -res : res;
    }
};


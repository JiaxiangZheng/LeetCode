#include <algorithm>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) //should not be const string&
    {
        string c;
        c.resize(std::max(a.size(), b.size())+1);
        std::reverse(a.begin(), a.end());
        std::reverse(b.begin(), b.end());
        bool add = false;
        int len = std::max(a.size(), b.size());
        int i = 0;
        for (; i<len; ++i)
        {
            int val =  add ? 1 : 0;
            if (i < a.size()) val += (a[i] - '0');
            if (i < b.size()) val += (b[i] - '0');
            if (val > 1) add = true, val -= 2;
            else add = false;
            c[i] = '0' + val;
        }
        if (add) c[i++] = '1';
        c[i] = '\0';
        std::reverse(c.begin(), c.end());
        return c;
    }
};


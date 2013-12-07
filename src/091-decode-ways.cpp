class Solution {
public:
    int numDecodings(string s) {
        if(s.size() == 0)
            return 0;
        vector<int> ways(s.size() + 2,1);//多出来的两个作为占位符，避免程序内判断是否超过size
        for(int i = s.size() - 1; i >= 0; --i)
        {
            //self
            if(s[i] == '0')
                ways[i] = 0;
            else
                ways[i] = ways[i+1];
            //self and next
            if( i + 1 < s.size() && ((s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6')))) {
                ways[i] += ways[i + 2];
            }
        }
        return ways[0];
    }
};


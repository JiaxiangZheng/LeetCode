/** 
 * Decode Ways 
 * A message containing letters from A-Z is being encoded to
 * numbers using the following mapping: 
 *  Given an encoded message containing digits, determine the 
 *  total number of ways to decode it.
For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
The number of ways decoding "12" is 2.
 */

/** 
""	0	0	
"0"	0	0	
"1"	1	1	
"2"	1	1	
"9"	1	1	
"10"	1	1	
"11"	2	2	"12"	2	2	"26"	2	2	"27"	2	1	"99"	2	1	"00"	0	0	"01"	0	0	"012"	0	0	"100"	2	0	"101"	2	1	"110"	3	1	"111"	3	3	"112"	3	3	"226"	3	3	"227"	3	2	"230"	3	0	"301"	2	0	"1001"	3	0	"1010"	3	1	"1029"	3	1	"1090"	3	0	* */ 
class Solution {
public:
    int numDecodings(const string& str)
    {
        if (str.empty()) return 0;
        if (str.size() == 1 && str[0] != '0') {
            return 1;
        }
        if (str[0] == '0') return 0;
        int *numArray = new int[str.size()];
        numArray[0] = 1;
        int val = (str[0]-'0')*10+str[1]-'0';
        if (0 < val <= 26) {
            if (str[1] == '0') numArray[1] = 1;
            else numArray[1] = 2;
        }
        else if (str[1] != '0') numArray[1] = 1;
        else {
            delete []numArray;
            return 0;
        }
        for (int i=2; i<str.size(); ++i)
        {
            val = (str[i-1]-'0')*10+(str[i]-'0');
            if (0 < val <= 26) numArray[i] = numArray[i-1] + numArray[i-2];
            else if (str[i] != '0')
                numArray[i] = numArray[i-1];
            else {
                delete []numArray;
                return 0;
            }
        }
        int res = numArray[str.size()-1];
        delete[] numArray;
        return res;
    }
};


#include <iostream>
#include <string>
using namespace std;

//Ñ°ÕÒ×Ö·û´®ÖÐ×î³¤»ØÎÄ×Ö·û´®
string expandAroundCenter(string s, int c1, int c2) {
  int l = c1, r = c2;
  int n = s.length();
  while (l >= 0 && r <= n-1 && s[l] == s[r]) {
    l--;
    r++;
  }
  return s.substr(l+1, r-l-1);
}
 
std::string LongestPalindromicSubString(const std::string& s)
{
  int n = s.length();
  if (n == 0) return "";
  string longest = s.substr(0, 1);  // a single char itself is a palindrome
  for (int i = 0; i < n-1; i++) {
    string p1 = expandAroundCenter(s, i, i);
    if (p1.length() > longest.length())
      longest = p1;
 
    string p2 = expandAroundCenter(s, i, i+1);
    if (p2.length() > longest.length())
      longest = p2;
  }
  return longest;
}

int main()
{
	std::string str;
	cin >> str;
    string substr = LongestPalindromicSubString(str);	
	std::cout << substr << endl;
	return 0;
}


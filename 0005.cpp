
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int maxLen = 0, offset = 0;

        for (int i = 0; i < n; i++)
        {
            IsPalindrome(s, i, i, maxLen, offset);
            IsPalindrome(s, i, i+1, maxLen, offset);            
        }

        return s.substr(offset, maxLen);
    }

    void IsPalindrome(string &s, int l, int r, int &maxLen, int &offset)
    {
        while (l >= 0 && r < s.length() && s[l] == s[r])
        {
            if (maxLen < (r-l+1))
            {
                maxLen = (r-l+1);
                offset = l;
            }
            l--;
            r++;
        }
    }
};
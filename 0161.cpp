
#include <string>
using namespace std;

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int slen = s.length(), tlen = t.length();

        if (s == t || abs(slen - tlen) > 1)   return false;
        int i = 0, j = 0, ndiff = 0;

        while (i < slen && j < tlen)
        {
            if (s[i] == t[j])
            {
                i++;
                j++;
            }
            else 
            {
                ndiff++;
                if (slen == tlen)   // replace
                {
                    i++;
                    j++;
                }
                else if (slen > tlen)   // delete
                    i++;
                else if (slen < tlen)   // insert
                    j++;
            }
            if (ndiff > 1) return false;
        }
        return true;
    }
};




#include <string>
using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        int l = 0, r = s.length() - 1;

        while (l < r)
        {
            if (s[l] != s[r])
                return Palindrome(s, l, r-1) || Palindrome(s, l + 1, r);
            l++;
            r--;
        }
        return true;
    }

    bool Palindrome(string s, int l, int r)
    {
        while (l < r)
            if (s[l++] != s[r--]) return false;
        return true;
    }
};
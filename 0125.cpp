
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int sIdx = 0, eIdx = s.length() - 1;

        while (sIdx < eIdx)
        {
            while (sIdx < eIdx && !isalnum(s[sIdx]))   sIdx++;
            while (sIdx < eIdx && !isalnum(s[eIdx]))   eIdx--;

            if (tolower(s[sIdx]) != tolower(s[eIdx]))   return false;

            ++sIdx;
            --eIdx;
        }
        return true;
    }
};

class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.length() - 1;

        while (l < r)
        {
            while (l < r && !isalnum(s[l])) l++;
            while (l < r && !isalnum(s[r])) r--;

            if (tolower(s[l++]) != tolower(s[r--])) return false;
        }
        return true;
    }
};



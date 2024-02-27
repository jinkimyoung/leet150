
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
        int start = 0;
        int end = s.size()-1;

        while (start < end)
        {
            if (!isalnum(s[start]))
            {   start++; 
                continue;
            }
            if (!isalnum(s[end])) 
            {   end--; 
                continue;
            }

            if (tolower(s[start]) != tolower(s[end])) return false;
            start++;
            end--;
        }
        return true;
    }
};


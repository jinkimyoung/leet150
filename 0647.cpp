
#include <string>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int cnt = 0;

        for (int i = 0; i < s.length(); i++)
        {
            Palindromic(s, i, i, cnt);
            Palindromic(s, i, i+1, cnt);            
        }
        return cnt;
    }

    void Palindromic(string &s, int l, int r, int &cnt)
    {
        while (l >= 0 && r < s.length() && s[l] == s[r])
        {
            cnt += 1;
            l--;
            r++;
        }
    }
};
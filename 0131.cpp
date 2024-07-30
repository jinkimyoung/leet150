// Time : O(n * 2^N)
// Space : O(n)
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> cur;
        bts(s, 0, cur, ans);
        return ans;
    }

    void bts(string s, int i, vector<string> &cur, vector<vector<string>> &ans)
    {
        if (i == s.length())
        {
            ans.push_back(cur);
            return ;
        }

        for (int j = i; j < s.length(); j++)
        {
            if (palindrome(s, i, j))
            {
                cur.push_back(s.substr(i, j - i + 1));
                bts(s, j+1, cur, ans);
                cur.pop_back();
            }
        }
    }

    bool palindrome(string &s, int l, int r)
    {
        while (l < r)
            if (s[l++] != s[r--])
                return false;
        return true;
    }
};




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
        dfs(s, 0, cur, ans);
        return ans;
    }

    bool isPalindrome(string s, int l, int r)
    {
        while (l < r)
            if (s[l++] != s[r--])
                return false;
        return true;
    }

    void dfs(string s, int idx, vector<string> &cur, vector<vector<string>> &ans)
    {
        if (idx == s.length())
        {
            ans.push_back(cur);
            return ;
        }

        for (int i = idx; i < s.length(); i++)
        {
            if (isPalindrome(s, idx, i))
            {
                string str = s.substr(idx, i-idx+1);
                cur.push_back(str);
                dfs(s, i+1, cur, ans);
                cur.pop_back();
            }
        }

    }
};
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        dfs(0, 0, "()", s, ans);
        return ans;
    }
    
    void dfs(int idx, int removed, char dir[], string s, vector<string> &res)
    {
        for (int i = idx, counter = 0; i < s.length(); i++)
        {
            if (s[i] == dir[0]) counter++;
            else if (s[i] == dir[1]) counter--;
            
            if (counter < 0)
            {
                for (int j = removed; j <= i; j++)
                    if (s[j] == dir[1] && (j == removed || s[j] != s[j-1]))
                        dfs(i, j, dir, s.substr(0, j) + s.substr(j+1), res);
                return ;
            }
        }
        reverse(s.begin(), s.end());
        if (dir[0] == '(')
            dfs(0, 0, ")(", s, res);
        else
            res.push_back(s);
    }
};



#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper(n, 0, 0, "", ans);
        return ans;
    }

    void helper(int n, int open, int close, string cur, vector<string> &ans)
    {
        if (open == n && close == n)
        {
            ans.push_back(cur);
            return ;
        }

        if (open < n)   helper(n, open+1, close, cur+"(", ans);
        if (open > close)   helper(n, open, close+1, cur+")", ans);
    }
};


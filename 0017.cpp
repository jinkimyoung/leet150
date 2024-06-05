
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        
        vector<string> res;
        unordered_map<char, string> mp = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "qprs"}, {'8', "tuv"}, {'9', "wxyz"}            
        };
        backtrack(mp, digits, 0, "", res);
        return res;
    }

    void backtrack(unordered_map<char, string> &mp, string &digits, int idx, string cur, vector<string> &res)
    {
        if (cur.length() == digits.length())
        {
            res.push_back(cur);
            return ;
        }

        for (char c : mp[digits[idx]])
            backtrack(mp, digits, idx+1, cur+c, res);
    } 
};
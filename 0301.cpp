


#include <string>
using namespace std;

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        dfs(0, 0, "()", s, res);
        return res;
    }
private:
    void dfs(int ind, int lastRm, char dir[], string s, vector<string> &res) {
        for(int i = ind, counter = 0; i < s.size(); ++i) {
            if(s[i] == dir[0]) ++counter;
            else if(s[i] == dir[1]) --counter;
            
            if(counter < 0) {
                for(int j = lastRm; j <= i; ++j) {
                    if(s[j] == dir[1] and (j == lastRm || s[j] != s[j - 1])) {
                        dfs(i, j, dir, s.substr(0, j) + s.substr(j + 1), res);
                    }
                }
                return;
            }
        }
        
        reverse(s.begin(), s.end());
        if(dir[0] == '(') dfs(0, 0, ")(", s, res);
        else res.push_back(s);
    }
};


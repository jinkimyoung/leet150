


#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        unordered_map<int, int> dp;
        dp[s.size()] = 1;
        return dfs(s, 0, dp);
    }

    int dfs(string s, int i, unordered_map<int, int> &dp)
    {
        if (dp.find(i) != dp.end())
            return dp[i];

        if (s[i] == '0')
            return 0;

        int res = dfs(s, i+1, dp);
        if (i + 1 < s.length() && (s[i]=='1' || (s[i]=='2' && s[i+1] <= '6')))
            res += dfs(s, i+2, dp);
    
        dp[i] = res;
        return res;
    }
};

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size()+1 , 0);
        dp[0] = 1;
        dp[1] = (s[0] == '0') ? 0 : 1;
        for(int i=2; i<=s.size(); i++){
            int first = s[i-1] - '0';
            int second = (s[i-2] - '0')*10 + (s[i-1] - '0');
            if(first>=1 && first<=9) dp[i] += dp[i-1];
            if(second>=10 && second<=26) dp[i] += dp[i-2];
        }
        return dp[s.size()];
    }
};


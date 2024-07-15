
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        dp[m][n] = true;
        
        for (int i = m; i >= 0; i--)
        {
            for (int j = n-1; j >= 0; j--)
            {
                bool bMatch = (i < m) && (s[i] == p[j] || p[j] == '.');
                if ((j+1) < n && p[j+1] == '*')
                {
                    dp[i][j] = dp[i][j+2];
                    if (bMatch)
                        dp[i][j] = dp[i][j] || dp[i+1][j];
                }
                else if (bMatch)
                    dp[i][j] = dp[i+1][j+1];
            }
        }
        
        return dp[0][0];
    }
};





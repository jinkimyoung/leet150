#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<bool> dp(n+1, false);
        dp[n] = true;

        for (int i = n-1; i >= 0; i--)
        {
            for (string word : wordDict)
            {
                int m = word.length();
                if (i + m <= n && s.substr(i, m) == word)
                    dp[i] = dp[i + m];
                if (dp[i])
                    break;
            }
        }
        return dp[0];
    }
};


// Using Cache
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int m = s.length();
        vector<bool> dp(m+1, false);
        dp[m] = true;
        
        for (int i = m; i >= 0; i--)
        {
            if (!dp[i]) continue;
            
            for (string word : wordDict)
            {
                if (i - word.length() > s.length()) continue;
                if (i - word.length() < 0) continue;
                
                if (s.substr(i - word.length(), word.length()) == word)
                    dp[i - word.length()] = true;
            }
        }
        return dp[0];
    }
};
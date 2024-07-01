

#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        unordered_map<long, int> dp;
        return dfs(0, true, prices, dp);
    }

    int dfs(int i, bool buying, vector<int> &prices, unordered_map<long, int> &dp)
    {
        if (i >= prices.size()) return 0;

        // combile 'i' and 'buying' into a single log key
        long key = static_cast<long>(i) << 1 | static_cast<long>(buying);
        if (dp.find(key) != dp.end())   
            return dp[key];

        int buy, sell, cooldown;
        if (buying)
        {
            cooldown  = dfs(i+1, true, prices, dp);
            buy = dfs(i+1, false, prices, dp) - prices[i];
            dp[key] = max(buy, cooldown);
        }
        else
        {
            cooldown  = dfs(i+1, false, prices, dp);            
            sell = dfs(i+2, true, prices, dp) + prices[i];
            dp[key] = max(sell, cooldown);            
        }
        return dp[key];
    }
};
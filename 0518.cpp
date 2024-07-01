
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        map<pair<int,int>, int> dp;

        return dfs(amount, coins, 0, 0, dp);
    }

    int dfs(int amount, vector<int> &coins, int idx, int sum, map<pair<int,int>, int> &dp)
    {
        if (sum == amount)  return 1;
        if (sum > amount || idx == coins.size())    return 0;
        if (dp.find({idx, sum}) != dp.end())   return dp[{idx, sum}];

        dp[{idx, sum}] = dfs(amount, coins, idx, sum+coins[idx], dp) + dfs(amount, coins, idx+1, sum, dp);
        return dp[{idx, sum}];
    }
};


#include <vector>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1, 0);
        dp[0] = 1;

        for (int coin : coins)
        {
            vector<int> nextDP(amount+1, 0);
            nextDP[0] = 1;

            for (int i = 1; i <= amount; i++)
            {
                nextDP[i] = dp[i];
                if (i >= coin)
                    nextDP[i] += nextDP[i-coin];
            }
            dp = nextDP;
        }
        return dp[amount];
    }
};

#include <vector>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1, 0);
        dp[0] = 1;
        for (int coin : coins)
        {
            vector<int> newDP = dp;
            for (int i = 1; i <= amount; i++)
            {
                if (i >= coin)
                    newDP[i] += newDP[i-coin];
            }
            dp = newDP;
        }
        return dp[amount] == INT_MAX ? 0 : dp[amount];
    }
};

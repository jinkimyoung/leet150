

#include <vector>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int num : nums)
            sum += num;
        
        if (abs(target) > sum || (sum + target) % 2)
            return 0;

        int m = (sum + target) / 2;
        vector<int> dp(m+1, 0);
        dp[0] = 1;

        for (int num : nums)
        {
            vector<int> nextDP(m+1, 0);
            for (int i = 0; i <= m; i++)
            {
                nextDP[i] = dp[i];
                if (i >= num)
                    nextDP[i] += dp[i - num];
            }
            dp = nextDP;
        }
        return dp[m];
    }
};


/*
    Given int array & a target, want to build expressions w/ '+' & '-'
    Return number of different expressions that evaluates to target

    Recursion w/ memoization, cache on (index, total), which stores # ways
    If total ever reaches the target, return 1 (this is a way), else 0

    Time: O(n x target)
    Space: O(n x target)
*/

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<long, int> dp; // Changed to long for key
        return backtrack(0, 0, nums, target, dp);
    }

    int backtrack(int i, int total, vector<int>& nums, int target, unordered_map<long, int>& dp) {
        if (i == nums.size()) {
            return total == target ? 1 : 0;
        }
        long key = static_cast<long>(i) << 32 | (total & 0xffffffffL); // Combine i and total into a single key
        if (dp.find(key) != dp.end()) {
            return dp[key];
        }

        int ways = backtrack(i + 1, total + nums[i], nums, target, dp) 
                + backtrack(i + 1, total - nums[i], nums, target, dp);
        dp[key] = ways;
        return ways;
    }
};



class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int num : nums)
            sum += num;
        if (abs(target) > sum  || (sum + target) % 2)  return 0;

        sum = (sum + target) >> 0x1;
        vector<int> dp(sum + 1, 0);
        dp[0] = 1;

        for (int num : nums)
        {
            vector<int> newDP(sum + 1, 0);
            newDP = dp;            
            for (int i = num; i <= sum; i++)
                newDP[i] += dp[i-num];

            dp = newDP;
        }
        return dp[sum];
    }
};


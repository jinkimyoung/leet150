
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if (n == 1) return nums[0];
        return max(helper(nums, 0, n-1), helper(nums, 1, n));
    }

    int helper(vector<int> &nums, int s, int l)
    {
        int n = nums.size();
        vector<int> dp(n+1, 0);

        dp[s+1] = nums[s];
        for (int i = s+2; i <= l; i++)
            dp[i] = max(dp[i-2]+nums[i-1], dp[i-1]);

        return dp[l];
    }
};


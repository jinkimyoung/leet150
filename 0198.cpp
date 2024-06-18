

// DP : Fibonacci 
// Time : O(N), Space : O(N)

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, 0);
  
        dp[0] = nums[0];
        for (int i = 2; i <= n; i++)
            dp[i] = max(dp[i-2]+nums[i-1], dp[i-1]);

        return dp[n];
    }
};


class Solution {


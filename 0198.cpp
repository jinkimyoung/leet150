

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
public:
    int rob(vector<int>& nums) {
        int rob1 = 0, rob2 = 0;
        for (int num : nums)
        {
            int temp = max(rob1 + num, rob2);
            rob1 = rob2;
            rob2 = temp;
        }
        return rob2;
    }
};



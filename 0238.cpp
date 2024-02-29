
// Time : O(N), Space : O(N)

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(), cur;
        vector<int> dp(n, 0);

        cur = 1;
        for (int i = 0; i < n; i++)
        {
           dp[i] = cur;
           cur = cur * nums[i]; 
        }

        cur = 1;
        for (int i = n - 1 ; i >= 0; i--)
        {
           dp[i] = dp[i] * cur;
           cur = cur * nums[i]; 
        }
        
	return dp;
    }
};
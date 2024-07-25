
#include <vector>
#include <algorithm>
using namespace std;

// Time : O(N * N)

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);

        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (nums[i] < nums[j])
                    dp[j] = max(dp[i] + 1, dp[j]);

        return *max_element(dp.begin(), dp.end());
    }
};


// Time : O(N * Log N)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis;

        for (int num : nums)
        {
            if (lis.empty() || lis.back() < num)
                lis.push_back(num);
            else
            {
                auto it = lower_bound(lis.begin(), lis.end(), num);
                *it = num;
            }
        }
        return lis.size();
    }
};

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        int l, r, sum;
        for (int i = 0; i < nums.size()-2; i++)
        {
            if (nums[i] > 0)    break;
            if (i > 0 && nums[i] == nums[i-1]) continue;

            l = i + 1;
            r = nums.size() - 1;
            while (l < r)
            {
                sum = nums[i] + nums[l] + nums[r];
                if (sum == 0)
                {
                    ans.push_back({nums[i], nums[l], nums[r]});

                    int prev_l = nums[l];
                    while (l < r && prev_l == nums[l]) l++;
                    int prev_r = nums[r];
                    while (l < r && prev_r == nums[r]) r--;
                }
                else if (sum < 0)
                    l = l + 1;
                else if (sum > 0)
                    r = r - 1;
            }
        }
        return ans;
    }
};

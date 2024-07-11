

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        dfs(nums, res, 0);
        return res;
    }

    void dfs(vector<int> &nums, vector<vector<int>> &ans, int idx)
    {
        if (idx == nums.size())
        {
            ans.push_back(nums);
            return ;
        }

        unordered_map<int, int> mp;
        for (int i = idx; i < nums.size(); i++)
        {
            if (mp.find(nums[i]) != mp.end())
                continue;
            
            mp[nums[i]]++;
            swap(nums[i], nums[idx]);
            dfs(nums, ans, idx+1);
            swap(nums[i], nums[idx]);            
        }
    }
};
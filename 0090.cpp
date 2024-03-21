
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;

        sort(nums.begin(), nums.end());
        dfs(nums, 0, cur, ans);
        return ans;
    }

    void dfs(vector<int> &nums, int idx, vector<int> &cur, vector<vector<int>> &ans)
    {
        ans.push_back(cur);
        for (int i = idx; i < nums.size(); i++)
        {
            if (i > idx && nums[i] == nums[i-1])
                continue;

            cur.push_back(nums[i]);
            dfs(nums, i+1, cur, ans);
            cur.pop_back();
        }
    }
};


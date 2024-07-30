
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> cur;
        sort(candidates.begin(), candidates.end());
        bts(candidates, target, 0, cur, ans);
        return ans;    
    }

    void bts(vector<int> &nums, int target, int idx, vector<int> &cur, vector<vector<int>> &ans)
    {
        if (target == 0)
        {
            ans.push_back(cur);
            return ;
        }
        if (target < 0 || idx >= nums.size()) return ;

        // Bruth force
        for (int prev = -1, i = idx; i < nums.size(); i++)
        {
            if (prev == nums[i]) continue;
            cur.push_back(nums[i]);
            bts(nums, target-nums[i], i+1, cur, ans);
            cur.pop_back();
            prev = nums[i];
        }
    }
};




#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        dfs(nums, 0, cur, ans);
        return ans;
    }

    void dfs(vector<int> &nums, int idx, vector<int> &cur, vector<vector<int>> &res)
    {
        res.push_back(cur);
        
        for (int i = idx; i < nums.size(); i++)
        {
            cur.push_back(nums[i]);
            dfs(nums, i+1, cur,res);    // i+1
            cur.pop_back();
        }
    }
};


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;

        dfs(nums, 0, cur, ans);
        return ans;
    }

    void dfs(vector<int> &nums, int idx, vector<int> &cur, vector<vector<int>> &ans)
    {
        if (idx == nums.size())
        {
            ans.push_back(cur);
            return ;
        }

        cur.push_back(nums[idx]);
        dfs(nums, idx+1, cur, ans);
        cur.pop_back();
        dfs(nums, idx+1, cur, ans);        
    }
};



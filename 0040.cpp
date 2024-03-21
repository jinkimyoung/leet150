
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> set;

        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, 0, set, ans);

        return ans;        
    }

    void dfs(vector<int>& candidates, int target, int sum, int start, vector<int> &set, vector<vector<int>> &ans)
    {
        if (sum > target)   return ;
        if (target == sum)
        {
            ans.push_back(set);
            return ;
        }

        for (int i = start; i < candidates.size(); i++)
        {
            if (i > start && candidates[i] == candidates[i-1])
                continue;
            set.push_back(candidates[i]);
            dfs(candidates, target, sum + candidates[i], i+1, set, ans);
            set.pop_back();
        }
    }
};
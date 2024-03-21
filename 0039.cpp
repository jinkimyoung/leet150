

#include <vector>
using namespace std;

// Time: O(2^target), Space: O(target)
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> cur;
        helper(candidates, target, 0, cur, ans);
        return ans;
    }

    void helper(vector<int>& cand, int target, int idx, vector<int> &cur, vector<vector<int>> &ans)
    {
        if (idx >= cand.size() || target < 0) return ;
        else if (target == 0)
        {
            ans.push_back(cur);
            return ;
        }
        // pick or not
        cur.push_back(cand[idx]);
        helper(cand, target-cand[idx], idx, cur, ans);
        cur.pop_back();
        helper(cand, target, idx+1, cur, ans);
    }
};


// K knapsack
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<vector<int>>> dp(target+1);
        for (int num : candidates)
        {
            for (int i = num; i <= target; i++)
            {
                if (i == num)
                    dp[i].push_back({num});
                else
                {
                    for (auto prev : dp[i-num])
                    {
                        prev.push_back(num);
                        dp[i].push_back(prev);
                    }
                }
            }
        }

        return dp[target];
    }
};

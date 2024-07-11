#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());

        for (auto cur : intervals)
        {
            if (ans.size() == 0 || ans.back()[1] < cur[0])
                ans.push_back(cur);
            else
            {
                ans.back()[0] = min(cur[0], ans.back()[0]);
                ans.back()[1] = max(cur[1], ans.back()[1]);                 
            }
        }
        return ans;
    }
};


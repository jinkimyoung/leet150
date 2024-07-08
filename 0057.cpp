


#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;

        sort(intervals.begin(), intervals.end());
        for (vector<int> interval : intervals)
        {
            if (interval[1] < newInterval[0])
                ans.push_back(interval);
            else if (newInterval[1] < interval[0])
            {
                ans.push_back(newInterval);
                newInterval = interval;
            }
            else
            {   // overwrapping
                newInterval[0] = min(newInterval[0], interval[0]);
                newInterval[1] = max(newInterval[1], interval[1]);                
            }
        }
        ans.push_back(newInterval);

        return ans;
    }
};

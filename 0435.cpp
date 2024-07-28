
#include <vector>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int ans = 0, prevE = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++)
        {
            if (prevE <= intervals[i][0])
                prevE = intervals[i][1];
            else
            {
                ans++;
                // min : to get minimum removals
                prevE = min(prevE, intervals[i][1]);                
            }
        }
        return ans;
    }
};
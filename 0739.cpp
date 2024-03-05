
// Time : O(N), Space : O(N)

#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(), 0);
        stack<pair<int, int>>   stk;    // temp : curday 

        for (int curDay = 0; curDay < temperatures.size(); curDay++)
        {
            while (!stk.empty() && stk.top().first < temperatures[curDay])
            {
                int prevDay = stk.top().second;
                ans[prevDay] = curDay - prevDay;
                stk.pop();
            }
            stk.push({temperatures[curDay], curDay});
        }
        return ans;
    }
};



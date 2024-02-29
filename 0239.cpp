
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;

        for (int l = 0, r = 0; r < nums.size(); r++)
        {
            while (!dq.empty() && nums[dq.back()] < nums[r])
                dq.pop_back();
            dq.push_back(r);
            if (l > dq.front())
                dq.pop_front();
            
            if (r + 1 >= k) 
            {
                ans.push_back(nums[dq.front()]);
                l++;
            }
        }
        return ans;
    }
};

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++)
        {
            pq.push({nums[i], i});
            if (i >= (k - 1))
            {
                while ((i - pq.top().second) >= k)
                {
                    pq.pop();
                }
                ans.push_back(pq.top().first);
            }
        }
        return ans;
    }
};
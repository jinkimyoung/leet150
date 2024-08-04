

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(begin(nums), end(nums));
        int diff = INT_MAX;

        for (int i = 0; i < nums.size() && diff != 0; ++i) 
        {
            int l = i + 1, r = nums.size() - 1;
            while (l < r)
            {
                int s = nums[i] + nums[l] + nums[r];
                if (abs(target - s) < abs(diff))
                    diff = target - s;
                
                if (s < target)
                    l++;
                else
                    r--;
            }
        }
        return target - diff;   // closed_sum
    }
};

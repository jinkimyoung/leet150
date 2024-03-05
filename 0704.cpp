
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, m;
        
        while (l <= r)
        {
            m = (l + r) / 2;
            if (target == nums[m])  return m;
            else if (target > nums[m])  l = m + 1;
            else if (target < nums[m])  r = m - 1;
        }
        return -1;
    }
};
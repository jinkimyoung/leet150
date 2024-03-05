
#include <vector>
using namespace std;

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int res = nums[0];
        int l = 0, r = nums.size() - 1, mid;

        while (l <= r)
        {
            if (nums[l] < nums[r])
            {
                res = min(res, nums[l]);
                break;
            }
            
            mid = l + (r - l) / 2;
            res = min(res, nums[mid]);
            if (nums[l] <= nums[mid]) // mid present in left sorted array
                l = mid + 1; // try to move closer to right sorted array
            else
                r = mid - 1;
        }

        return res;
    }
};
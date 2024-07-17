

#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        return bsearch(nums, 0, nums.size() - 1);
    }

    int bsearch(vector<int> &nums, int l, int r)
    {
        if (l == r) return l;
        int mid = (l + r) / 2;

        if (nums[mid] > nums[mid+1])
            return bsearch(nums, l, mid);
        else
            return bsearch(nums, mid+1, r);
    }
};


#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (nums[mid] > nums[mid + 1])
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};
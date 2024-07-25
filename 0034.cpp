#include <iostream>    
#include <vector>
using namespace std;
    
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first, second;

        first = lower_bound(nums, target);
        second = lower_bound(nums, target+1)-1;
        if (first < nums.size() && second < nums.size() && nums[first] == target && nums[second] == target)
            return {first, second};

        return {-1, -1};        
    }

    int lower_bound(vector<int>& nums, int target)
    {
        int low = 0, high = nums.size() - 1, mid = 0;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (nums[mid] < target)
                low = mid + 1;
            else            
                high = mid - 1;
        }
        return low; 
    }
};


class Solution {
public:
    int firstBadVersion(int n) {
        long low = 1, high = n, mid;
        
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (isBadVersion(mid))
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};



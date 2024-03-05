
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;

        for (int num : nums)
        {
            if (mp.find(num) != mp.end())   return num;
            mp[num] = 1;
        }
        return 0;
    }
};

// Time : O(N), Space : O(1)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int s = nums[0], f = nums[nums[0]];
        while (s != f)
        {
            s = nums[s];
            f = nums[nums[f]];
        }

        s = 0;
        while (s != f)
        {
            s = nums[s];
            f = nums[f];
        }
        return s;
    }
};


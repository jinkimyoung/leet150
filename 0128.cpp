
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int ans = 0, len;
        for (int num : nums)
        {
            if (s.find(num-1) != s.end())
                continue;

            len = 0;
            while (s.find(num++) != s.end())
                len++;
            ans = max(ans, len);
        }
        return ans;
    }
};  
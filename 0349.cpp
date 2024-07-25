

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int, bool> mp;

        for (int num : nums1)
            mp[num] = true;

        for (int num : nums2)
            if (mp[num])
            {
                ans.push_back(num);
                mp[num] = false;
            }

        return ans;
    }
};